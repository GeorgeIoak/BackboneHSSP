using System;
using System.IO;
using System.ComponentModel;
using System.Windows.Forms;

namespace HexFileParser
{
    /// <summary>
    /// Class containing the hex file parsing logic
    /// </summary>
    public partial class FormHexFileParser : Form
    {

        /* Constant Defintions */
        internal const int CHECKSUM_HEADER_LENGTH = 9;
        internal const int CHECKSUM_BYTE_LENGTH = 2;
        internal const string CHECKSUM_REGION_START = ":0200000490303A";

        internal const int SILICON_ID_HEADER_LENGTH = 13;
        internal const int SILICON_ID_BYTE_LENGTH = 4;
        internal const string SILICON_ID_REGION_START = ":0200000490501A";

        internal const int MAX_DATA_BYTES_PER_HEX_ROW = 64;
        internal const int MAX_DATA_CHARACTERS_PER_HEX_ROW = 128;

        internal const int BYTES_PER_FLASH_ROW = 128;

        internal const int FLASH_DATA_HEADER_LENGTH = 9;
        internal const int END_OF_LINE_CHECKSUM_BYTE_COUNT = 2;

        internal const int FLASH_ROWS_PER_PROTECTION_BYTE = 8;
        internal const int FLASH_PROTECTION_HEADER_LENGTH = 9;
        internal const string FLASH_PROTECTION_REGION_START = ":0200000490402A";

        internal const int CHIP_PROT_HEADER_LENGTH = 9;
        internal const string CHIP_PROT_REGION_START = ":0200000490600A";

        internal const int HEX_FILE_LINES_PER_FLASH_ROW = 2;

        internal const char HEX_FILE_DATA_RECORD_CHAR_0 = '0';
        internal const char HEX_FILE_DATA_RECORD_CHAR_1 = '0';

        internal const char HEX_FILE_EXTEND_LINEAR_RECORD_CHAR_0 = '0';
        internal const char HEX_FILE_EXTEND_LINEAR_RECORD_CHAR_1 = '4';

        internal const int HEX_FILE_RECORD_TYPE_CHAR_0_INDEX = 7;
        internal const int HEX_FILE_RECORD_TYPE_CHAR_1_INDEX = 8;

        internal const int HEX_FILE_EXTENDED_ADDR_CHAR_1_INDEX = 9;

        internal const char HEX_FILE_EXTENDED_ADDR_NON_FLASH_REGION = '8';

        /* Global variables */

        string m_pathHexFile, m_pathCfile, m_pathHfile; /* Path variables for Source Hex File, Target .c, .h file locattions */
        StreamWriter m_swCfile; /* Stream Writer object to .c file */
        StreamWriter m_swHfile; /* Stream Writer object to .h file */
        StreamReader m_srFlashMainData;  /* Hex File Stream Reader object to get main Flash data */
        int m_numberOfFlashRows = 0; /* Total number of Flash rows in hex file */
        int m_bytesPerHexRow;           /* Bytes per row of hex file */
        int m_bytesPerFlashRow;      /* Bytes per row of flash */

        /* Code generated automatically by Visual Studio */
        public FormHexFileParser()
        {
            InitializeComponent();

            openFileDialogSourceHex.InitialDirectory = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments), "\\PSoC Creator\\"); 
        }

        private void buttonSourceHexFile_Click(object sender, EventArgs e)
        {

            /* Show files with extension *.hex */
            openFileDialogSourceHex.Title = "Open Hex File";
            openFileDialogSourceHex.Filter = "Hex files (*.hex)|*.hex";
            openFileDialogSourceHex.FilterIndex = 1;
            openFileDialogSourceHex.RestoreDirectory = true;

            /* If hex file exists, get the hex file name and display in text box */
            if (openFileDialogSourceHex.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    if (openFileDialogSourceHex.OpenFile() != null)
                    {
                        textBoxHexFile.Text = openFileDialogSourceHex.FileName;
                    }
                }
                /* File does not exist exception */
                catch (Exception ex)
                {
                    MessageBox.Show("Error: Could not open the file from the disk. Original error: " + ex.Message);
                }
            }
        }

        private void buttonTargetLocation_Click(object sender, EventArgs e)
        {
            /* If folder exists, display folder location in text box */
            if (folderBrowserDialogTargetFile.ShowDialog() == DialogResult.OK)
            {
                if (folderBrowserDialogTargetFile.SelectedPath != null)
                {
                    textBoxTargetLocation.Text = folderBrowserDialogTargetFile.SelectedPath;
                }
            }
        }

        private void buttonParser_Click(object sender, EventArgs e)
        {
            /* Get the path locations for source, target files */
            m_pathHexFile = textBoxHexFile.Text;
            m_pathCfile = Path.Combine(textBoxTargetLocation.Text, "HexImage.c");
            m_pathHfile = Path.Combine(textBoxTargetLocation.Text, "HexImage.h");
            /* Abort if source hex file does not exist at the specified location */
            if (!File.Exists(m_pathHexFile))
            {
                MessageBox.Show("Hex File does not exist at the specified location");
                return;
            }

            /* Create a new .c file HexImage.c, HexImage.h files at specified location if the file does not exist */
            if ((!File.Exists(m_pathCfile)) && (!File.Exists(m_pathHfile)))
            {
                /* Create a .c file to write the data. */
                using (m_swCfile = File.CreateText(m_pathCfile))
                {
                    AppendSourceFileHeader();       /* Add top level comments to generated .c file */
                    ParseSiliconId();               /* Add Device Silicon ID data  from hex file to generated .c file */
                    ParseChecksum();                /* Add Hex File Checksum data from hex file to generated .c file */

                    m_numberOfFlashRows = CalculateFlashRowCount(); /* Get the number of Flash rows for the device from hex file */

                    ParseFlashProtectionData();     /* Add Flash Protection data from hex file to generated .c file */
                    ParseChipProtectionData();      /* Add chip Protection data from hex file to generated .c file */
                    ParseFlashData();               /* Add Flash data from hex file to generated .c file */
                    AppendSourceFileTrailer();      /* Add closing comments to generated .c file */
                    m_swCfile.Close();                /* Close .c file */
                }

                /* Create a file to write the data */
                using (m_swHfile = File.CreateText(m_pathHfile))
                {
                    WriteHeaderFile();              /* Create the .h file */
                    m_swHfile.Close();                /* Close .h file */
                }
            }
            else
            {
                if(File.Exists(m_pathCfile))
                {
                    MessageBox.Show("Error: A file with the name HexImage.c already exists in the specified Target folder location. Change the Target Folder location or delete the existing HexImage.c file to continue.");
                }

                if (File.Exists(m_pathHfile))
                {
                    MessageBox.Show("Error: A file with the name HexImage.h already exists in the specified Target folder location. Change the Target Folder location or delete the existing HexImage.h file to continue.");
                }
                
                return;                
            }
            
            DialogResult result;

            result = MessageBox.Show("Hex File Parsing completed", "Message", MessageBoxButtons.OK);
        }

        private void textBoxHexFile_MouseHover(object sender, EventArgs e)
        {
            toolTipMessage.SetToolTip(textBoxHexFile, textBoxHexFile.Text);
        }

        private void textBoxTargetLocation_MouseHover(object sender, EventArgs e)
        {
            toolTipMessage.SetToolTip(textBoxTargetLocation, textBoxTargetLocation.Text);
        }

        /* Add top level comments to generated .c file */
        private void AppendSourceFileHeader()
        {
            String SourceHeader = "/*****************************************************************************\n" +
                                  "* File Name: HexImage.c\n" +
                                  "**\n" +
                                  "Version: 1.0\n" +
                                  "**\n" +
                                  "Description:\n" +
                                  "* 1.) This source file defines the Hex file data as an Array of constants.\n" +
                                  "*     It defines constant arrays for Flash data, Flash protection data, \n" + 
                                  "*     Verification checksum, Device Silicon Id, Device Revision Id. \n" +
                                  "* 2.) It provides access to the Hex file data organized as an array of\n" +
                                  "*     constants.\n" +
                                  "* 3.) This source file is generated by C# application \"HexFile Parser\" \n" +
                                  "*     with the actual hex file to be programmed as input to C# application.\n" +
                                  "*\n" +
                                  "**\n" +
                                  "Note:\n" +
                                  "*\n" +
                                  "**\n" +
                                  "Owner:\n" +
                                  "* TUSR\n" +
                                  "**\n" +
                                  "Related Document:\n" +
                                  "* Refer to the application note document for details on application\n" +
                                  "**\n" +
                                  "Code Tested With:\n" +
                                  "*  Microsoft Visual Studio Express 2013 for Windows Desktop (Version 12.0.21005.1 REL)\n" +
                                  "*****************************************************************************/ \n\n" +
                                  "#include \"HexImage.h\" \n";

            m_swCfile.Write(SourceHeader);
            m_swCfile.WriteLine();
        }

        /* Add Hex File Checksum data from hex file to generated .c file */
        private void ParseChecksum()
        {
            bool checksumDetected = false;
            String readData;
            StreamReader srHexFile = File.OpenText(m_pathHexFile);

            /* Parse through the hex file till Hex File Checksum region is reached  */
            while ((readData = srHexFile.ReadLine()) != null)
            {
                /* If Hex File Checksum region is reached, get Checksum data  */
                if (checksumDetected == true)
                {
                    readData = readData.Remove(0, CHECKSUM_HEADER_LENGTH); /* Remove header information from hex row */
                    m_swCfile.Write("unsigned char const checksumData_HexFile[2] = {");
                    for (int i = 0; i < CHECKSUM_BYTE_LENGTH; i++)
                    {
                        /* Checksum data is in big-endian format. Store as bytes in little endian format */
                        m_swCfile.Write("0x" + readData[2 * (1 - i)] + readData[(2 * (1 - i)) + 1]);
                        if (i != (CHECKSUM_BYTE_LENGTH -1))
                        {
                            m_swCfile.Write(", ");
                        }
                        else
                        {
                            m_swCfile.WriteLine("};");
                            m_swCfile.WriteLine();
                        }
                    }
                    
                    break;

                }

                /* Checksum is at address 0x9030 0000 of .hex file */
                if (String.Equals(readData, CHECKSUM_REGION_START))
                {
                    checksumDetected = true;
                }
            }
        }

        /* Add Device Silicon ID data  from hex file to generated .c file */
        private void ParseSiliconId()
        {
            bool siliconIdDetected = false;
            String readData;
            StreamReader srHexFile = File.OpenText(m_pathHexFile);

            /* Parse through the hex file till Silicon ID region is reached  */
            while ((readData = srHexFile.ReadLine()) != null)
            {
                /* If Hex File Silicon ID region is reached, get Silicon ID data  */
                if (siliconIdDetected == true)
                {
                    readData = readData.Remove(0, SILICON_ID_HEADER_LENGTH); /* Remove header information from hex row */

                    m_swCfile.Write("unsigned char const deviceSiliconId_HexFile[4] = {");
                    for (int i = 0; i < SILICON_ID_BYTE_LENGTH; i++)
                    {
                        m_swCfile.Write("0x" + readData[2 * (i)] + readData[(2 * (i)) + 1]);
                        if (i != (SILICON_ID_BYTE_LENGTH - 1))
                        {
                            m_swCfile.Write(", ");
                        }
                        else
                        {
                            m_swCfile.WriteLine("};");
                        }
                    }

                    m_swCfile.WriteLine();
                    
                    break;
                }

                /* Silicon ID is at address 0x9050 0000 of .hex file */
                if (String.Equals(readData, SILICON_ID_REGION_START))
                {
                    siliconIdDetected = true;
                }
            }
        }

        /* Add Flash data from hex file to generated .c file */
        private void ParseFlashData()
        {
            m_srFlashMainData = File.OpenText(m_pathHexFile); /* Open the .hex file in Stream class for parsing Flash data */

            m_bytesPerHexRow = MAX_DATA_BYTES_PER_HEX_ROW;
            m_bytesPerFlashRow = BYTES_PER_FLASH_ROW;

            String flashHeaderString = "unsigned char const flashData_HexFile[NUMBER_OF_FLASH_ROWS_HEX_FILE][FLASH_ROW_BYTE_SIZE_HEX_FILE]  = { ";

            String dummyHeaderString = "";

            for (int i = 0; i < flashHeaderString.Length; i++)
            {
                dummyHeaderString += " ";
            }

            m_swCfile.WriteLine(flashHeaderString);

            int rowNumber = 0;

            /* Extract the flash data for each row */
            for (rowNumber = 0; rowNumber < m_numberOfFlashRows; rowNumber++)
            {
                m_swCfile.Write(dummyHeaderString + "{");

                ParseFlashRowData();

                if (rowNumber == (m_numberOfFlashRows - 1))
                {
                    m_swCfile.WriteLine("}");
                    dummyHeaderString = dummyHeaderString.Remove(0, 2);
                    m_swCfile.WriteLine(dummyHeaderString + "};");
                    m_swCfile.WriteLine();
                }
                else
                {
                    m_swCfile.WriteLine("},");
                }

            }
        }

        /* Add Flash protection data from hex file to the generated .c file */
        private void ParseFlashProtectionData()
        {
            bool flashProtectionDataDetected = false;
            String readData;
            StreamReader srHexFile = File.OpenText(m_pathHexFile);            

            int numberOfFlashProtectionBytesLeft = m_numberOfFlashRows / FLASH_ROWS_PER_PROTECTION_BYTE;

            /* Loop till the end of the hex file is reached */
            while ((readData = srHexFile.ReadLine()) != null)
            {

                if (flashProtectionDataDetected == true)
                {

                    m_swCfile.Write("unsigned char const flashProtectionData_HexFile[FLASH_PROTECTION_BYTE_SIZE_HEX_FILE] = {");

                    while (numberOfFlashProtectionBytesLeft > 0)
                    {
                        readData = readData.Remove(0, FLASH_PROTECTION_HEADER_LENGTH); /* Remove the header from the hex file line */

                        if (numberOfFlashProtectionBytesLeft > MAX_DATA_BYTES_PER_HEX_ROW)
                        {
                            readData = readData.Substring(0, MAX_DATA_CHARACTERS_PER_HEX_ROW);

                            for (int i = 0; i < MAX_DATA_BYTES_PER_HEX_ROW; i++)
                            {
                                /* Write the Flash protection data to the .c file */
                                m_swCfile.Write("0x" + readData[2 * i] + readData[(2 * i) + 1]);
                                m_swCfile.Write(", ");
                            }

                            numberOfFlashProtectionBytesLeft -= MAX_DATA_BYTES_PER_HEX_ROW;
                            readData = srHexFile.ReadLine();
                        }
                        else
                        {
                            readData = readData.Substring(0, (2 * numberOfFlashProtectionBytesLeft));

                            for (int i = 0; i < numberOfFlashProtectionBytesLeft; i++)
                            {
                                /* Write the Flash protection data to the .c file */
                                m_swCfile.Write("0x" + readData[2 * i] + readData[(2 * i) + 1]);

                                if (i != (numberOfFlashProtectionBytesLeft - 1))
                                {
                                    m_swCfile.Write(", ");
                                }
                                else
                                {
                                    m_swCfile.WriteLine("};");
                                    m_swCfile.WriteLine();
                                }
                            }

                            break;
                        }
                    }

                    flashProtectionDataDetected = false;
                }
                /* Header that denotes the start of protection data in the hex file */
                if (String.Equals(readData, FLASH_PROTECTION_REGION_START))
                {
                    flashProtectionDataDetected = true;                    
                }
            }
        }
        
        /* Add Chip protection data from hex file to the generated .c file */
        private void ParseChipProtectionData()
        {
            bool chipProtectionDataDetected = false;
            String readData;
            StreamReader srHexFile = File.OpenText(m_pathHexFile);
                        
            /* Loop till the end of the hex file is reached */
            while ((readData = srHexFile.ReadLine()) != null)
            {
                if (chipProtectionDataDetected == true)
                {
                    readData = readData.Remove(0, CHIP_PROT_HEADER_LENGTH); /* Remove the header from the hex file line */                    

                    m_swCfile.Write("unsigned char const chipProtectionData_HexFile = ");

                    /* Write the chip protection data to the .c file */
                    m_swCfile.Write("0x" + readData[0] + readData[1]);
                    m_swCfile.WriteLine(";");
                    m_swCfile.WriteLine();

                    break;
                }
                
                /* Header that denotes the start of protection data in the hex file */
                if (String.Equals(readData, CHIP_PROT_REGION_START))
                {
                    chipProtectionDataDetected = true;
                }
            }
        }

        /* Add Flash row data from hex file to generated .c file */
        private void ParseFlashRowData()
        {
            String readData = "";
            String hexRowData = "";
            /* Two lines of hex file have the data for one flash row */
            
            /* Read one line of hex file */
            hexRowData = m_srFlashMainData.ReadLine();
            /* If the current line read is a bank header line, skip the line */
            /* and read another line */
            if (hexRowData.Length < MAX_DATA_CHARACTERS_PER_HEX_ROW) 
                hexRowData = m_srFlashMainData.ReadLine();
            hexRowData = hexRowData.Remove(0, FLASH_DATA_HEADER_LENGTH); /* Remove the meta data at the beginning of the line in the hex file */
            hexRowData = hexRowData.Remove(MAX_DATA_CHARACTERS_PER_HEX_ROW, END_OF_LINE_CHECKSUM_BYTE_COUNT); /* Remove the meta data at the end of the line in the hex file */
            readData = hexRowData; /* Append the data to form a flash row */

            /* Write the 64 bytes flash row data (128 ASCII chars from hex file per row) to the .c file */
            for (int i = 0; i < m_bytesPerHexRow; i++)
            {
                m_swCfile.Write("0x" + readData[2 * i] + readData[(2 * i) + 1]);
                if (i != (m_bytesPerHexRow - 1))
                {
                    m_swCfile.Write(", ");
                }
            }
            
            m_swCfile.Write(", ");

            readData = "";
            /* Read second line of hex file */
            hexRowData = m_srFlashMainData.ReadLine();
            /* If the current line read is a bank header line, skip the line */
            /* and read another line */
            if (hexRowData.Length < MAX_DATA_CHARACTERS_PER_HEX_ROW)
                hexRowData = m_srFlashMainData.ReadLine();
            hexRowData = hexRowData.Remove(0, FLASH_DATA_HEADER_LENGTH); /* Remove the meta data at the beginning of the line in the hex file */
            hexRowData = hexRowData.Remove(MAX_DATA_CHARACTERS_PER_HEX_ROW, END_OF_LINE_CHECKSUM_BYTE_COUNT); /* Remove the meta data at the end of the line in the hex file */
            readData = readData + hexRowData; /* Append the data to form a flash row */

            /* Write the 64 bytes flash row data (128 ASCII chars from hex file per row) to the .c file */
            for (int i = 0; i < m_bytesPerHexRow; i++)
            {
                m_swCfile.Write("0x" + readData[2 * i] + readData[(2 * i) + 1]);
                if (i != (m_bytesPerHexRow - 1))
                {
                    m_swCfile.Write(", ");
                }
            }
        }

        /* Calculate the number of Flash rows from the hex file */
        private int CalculateFlashRowCount()
        {
            int lineNumber = 0;
            String readData;
            StreamReader srHexFile = File.OpenText(m_pathHexFile);

            /* Loop till the main flash row data ends, which will be used to calculate the number of lines in hex file for
             * flash rows.  Each line of hex file will have data for 1/2 th of a Flash row (64 bytes)*/
            while ((readData = srHexFile.ReadLine()) != null)
            {

                if ((readData[HEX_FILE_RECORD_TYPE_CHAR_0_INDEX] == HEX_FILE_DATA_RECORD_CHAR_0) && (readData[HEX_FILE_RECORD_TYPE_CHAR_1_INDEX] == HEX_FILE_DATA_RECORD_CHAR_1))
                {
                    lineNumber++;
                }
                else
                {

                    if ((readData[HEX_FILE_RECORD_TYPE_CHAR_0_INDEX] == HEX_FILE_EXTEND_LINEAR_RECORD_CHAR_0) &&
                        (readData[HEX_FILE_RECORD_TYPE_CHAR_1_INDEX] == HEX_FILE_EXTEND_LINEAR_RECORD_CHAR_1))
                    {
                        if (readData[HEX_FILE_EXTENDED_ADDR_CHAR_1_INDEX] >= HEX_FILE_EXTENDED_ADDR_NON_FLASH_REGION)
                        {
                            break;
                        }
                    }
                }

            }

            return (lineNumber / HEX_FILE_LINES_PER_FLASH_ROW);
        }

        /* Append Trailer data for source c file */
        private void AppendSourceFileTrailer()
        {
            String sourceTrailer = "\n/* [] END OF FILE */\n";
            m_swCfile.Write(sourceTrailer);
        }

        /* Generate the header file with declaration for array of constants */
        private void WriteHeaderFile()
        {
            String headerFileHeader = "/*****************************************************************************\n" +
                      "* File Name: HexImage.h\n" +
                      "**\n" +
                      "Version: 1.0\n" +
                      "**\n" +
                      "Description:\n" +
                      "* 1.) This is the header file of HexImage.c\n" +
                      "* 2.) It provides access to the Hex file data organized as an array of constants.\n" +
                      "* 3.) This header file is generated by the C# application \"HexFile Parser\" with\n" +
                      "*     the actual hex file to be programmed as input to C# application.\n" +
                      "**\n" +
                      "Note:\n" +
                      "**\n" +
                      "Owner:\n" +
                      "* TUSR\n" +
                      "**\n" +
                      "**\n" +
                      "Related Document:\n" +
                      "* Refer to the application note document for details on application\n" +
                      "**\n" +
                      "Code Tested With:\n" +
                      "*  Microsoft Visual Studio Express 2013 for Windows Desktop (Version 12.0.21005.1 REL)\n" +
                      "*****************************************************************************/\n" +
                      "\n" +
                      "#ifndef __HEXIMAGE_H \n" +
                      "#define __HEXIMAGE_H \n" +
                      "\n" +
                      "/*****************************************************************************\n" +
                      "* MACRO Definitions \n" +
                      "******************************************************************************/ \n";
           
            m_swHfile.Write(headerFileHeader);
            m_swHfile.WriteLine();

            m_swHfile.WriteLine("#define CY8C4xx7_BL_FAMILY                    1");
            m_swHfile.WriteLine("#define NUMBER_OF_FLASH_ROWS_HEX_FILE        " + Convert.ToString(m_numberOfFlashRows));
            m_swHfile.WriteLine("#define FLASH_ROW_BYTE_SIZE_HEX_FILE         " + Convert.ToString(m_bytesPerFlashRow));
            m_swHfile.WriteLine("#define FLASH_PROTECTION_BYTE_SIZE_HEX_FILE  " + Convert.ToString(m_numberOfFlashRows / 8));
            m_swHfile.WriteLine();

            String HeaderFileTrailer = " /*****************************************************************************\n" +
                                       " * Global Constant Declarations \n" +
                                       "  ****************************************************************************/\n \n" +
                                       "extern unsigned char const deviceSiliconId_HexFile[4]; \n" +
                                       "extern unsigned char const checksumData_HexFile[2]; \n" +
                                       "extern unsigned char const flashData_HexFile[NUMBER_OF_FLASH_ROWS_HEX_FILE][FLASH_ROW_BYTE_SIZE_HEX_FILE]; \n" +
                                       "extern unsigned char const flashProtectionData_HexFile[FLASH_PROTECTION_BYTE_SIZE_HEX_FILE]; \n" +
                                       "extern unsigned char const chipProtectionData_HexFile; \n \n" +
                                       "#endif /* __HEXIMAGE_H */ \n \n" +
                                       "/* [] END OF FILE */ \n";

            m_swHfile.Write(HeaderFileTrailer);
        }
        
    }
}
