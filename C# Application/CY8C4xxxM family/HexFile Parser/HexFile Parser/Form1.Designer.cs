namespace HexFileParser
{
    partial class FormHexFileParser
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.folderBrowserDialogTargetFile = new System.Windows.Forms.FolderBrowserDialog();
            this.openFileDialogSourceHex = new System.Windows.Forms.OpenFileDialog();
            this.buttonParser = new System.Windows.Forms.Button();
            this.buttonTargetLocation = new System.Windows.Forms.Button();
            this.toolTipMessage = new System.Windows.Forms.ToolTip(this.components);
            this.textBoxTargetLocation = new System.Windows.Forms.TextBox();
            this.textBoxHexFile = new System.Windows.Forms.TextBox();
            this.buttonSourceHexFile = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // buttonParser
            // 
            this.buttonParser.Location = new System.Drawing.Point(252, 287);
            this.buttonParser.Name = "buttonParser";
            this.buttonParser.Size = new System.Drawing.Size(147, 23);
            this.buttonParser.TabIndex = 9;
            this.buttonParser.Text = "Parse Hex File";
            this.buttonParser.UseVisualStyleBackColor = true;
            this.buttonParser.Click += new System.EventHandler(this.buttonParser_Click);
            // 
            // buttonTargetLocation
            // 
            this.buttonTargetLocation.Location = new System.Drawing.Point(542, 136);
            this.buttonTargetLocation.Name = "buttonTargetLocation";
            this.buttonTargetLocation.Size = new System.Drawing.Size(147, 23);
            this.buttonTargetLocation.TabIndex = 8;
            this.buttonTargetLocation.Text = "Select Target File Folder";
            this.buttonTargetLocation.UseVisualStyleBackColor = true;
            this.buttonTargetLocation.Click += new System.EventHandler(this.buttonTargetLocation_Click);
            // 
            // textBoxTargetLocation
            // 
            this.textBoxTargetLocation.Location = new System.Drawing.Point(37, 136);
            this.textBoxTargetLocation.Name = "textBoxTargetLocation";
            this.textBoxTargetLocation.Size = new System.Drawing.Size(465, 20);
            this.textBoxTargetLocation.TabIndex = 7;
            this.textBoxTargetLocation.MouseHover += new System.EventHandler(this.textBoxTargetLocation_MouseHover);
            // 
            // textBoxHexFile
            // 
            this.textBoxHexFile.Location = new System.Drawing.Point(37, 29);
            this.textBoxHexFile.Name = "textBoxHexFile";
            this.textBoxHexFile.Size = new System.Drawing.Size(465, 20);
            this.textBoxHexFile.TabIndex = 6;
            this.textBoxHexFile.MouseHover += new System.EventHandler(this.textBoxHexFile_MouseHover);
            // 
            // buttonSourceHexFile
            // 
            this.buttonSourceHexFile.Location = new System.Drawing.Point(542, 29);
            this.buttonSourceHexFile.Name = "buttonSourceHexFile";
            this.buttonSourceHexFile.Size = new System.Drawing.Size(147, 23);
            this.buttonSourceHexFile.TabIndex = 5;
            this.buttonSourceHexFile.Text = "Open Source P4 Hex File";
            this.buttonSourceHexFile.UseVisualStyleBackColor = true;
            this.buttonSourceHexFile.Click += new System.EventHandler(this.buttonSourceHexFile_Click);
            // 
            // FormHexFileParser
            // 
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Inherit;
            this.ClientSize = new System.Drawing.Size(711, 488);
            this.Controls.Add(this.buttonParser);
            this.Controls.Add(this.buttonTargetLocation);
            this.Controls.Add(this.textBoxTargetLocation);
            this.Controls.Add(this.textBoxHexFile);
            this.Controls.Add(this.buttonSourceHexFile);
            this.Name = "FormHexFileParser";
            this.Text = "HexFile Parser";            
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.FolderBrowserDialog folderBrowserDialogTargetFile;
        private System.Windows.Forms.OpenFileDialog openFileDialogSourceHex;
        private System.Windows.Forms.Button buttonParser;
        private System.Windows.Forms.Button buttonTargetLocation;
        private System.Windows.Forms.ToolTip toolTipMessage;
        private System.Windows.Forms.TextBox textBoxTargetLocation;
        private System.Windows.Forms.TextBox textBoxHexFile;
        private System.Windows.Forms.Button buttonSourceHexFile;
    }
}

