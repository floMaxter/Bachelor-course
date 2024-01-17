
namespace All_Lab
{
    partial class ParssingForm
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
            this.mainPanel = new System.Windows.Forms.Panel();
            this.textPanel = new System.Windows.Forms.Panel();
            this.mainTextBox = new System.Windows.Forms.TextBox();
            this.mainRichTextBox = new System.Windows.Forms.RichTextBox();
            this.settingsPanel = new System.Windows.Forms.Panel();
            this.buttonTimeRange = new System.Windows.Forms.Button();
            this.textBoxSecondTime = new System.Windows.Forms.TextBox();
            this.textBoxFirstTime = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.labelDataTime = new System.Windows.Forms.Label();
            this.formSearchbutton = new System.Windows.Forms.Button();
            this.signatureSearchButton = new System.Windows.Forms.Button();
            this.addButton = new System.Windows.Forms.Button();
            this.inclusionButton = new System.Windows.Forms.Button();
            this.openFileButton = new System.Windows.Forms.Button();
            this.signatureLabel = new System.Windows.Forms.Label();
            this.comboBoxSignature = new System.Windows.Forms.ComboBox();
            this.mainPanel.SuspendLayout();
            this.textPanel.SuspendLayout();
            this.settingsPanel.SuspendLayout();
            this.SuspendLayout();
            // 
            // mainPanel
            // 
            this.mainPanel.Controls.Add(this.textPanel);
            this.mainPanel.Controls.Add(this.settingsPanel);
            this.mainPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.mainPanel.Location = new System.Drawing.Point(0, 0);
            this.mainPanel.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.mainPanel.Name = "mainPanel";
            this.mainPanel.Size = new System.Drawing.Size(1180, 572);
            this.mainPanel.TabIndex = 0;
            // 
            // textPanel
            // 
            this.textPanel.Controls.Add(this.mainTextBox);
            this.textPanel.Controls.Add(this.mainRichTextBox);
            this.textPanel.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.textPanel.Location = new System.Drawing.Point(0, 166);
            this.textPanel.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.textPanel.Name = "textPanel";
            this.textPanel.Size = new System.Drawing.Size(1180, 406);
            this.textPanel.TabIndex = 1;
            // 
            // mainTextBox
            // 
            this.mainTextBox.Dock = System.Windows.Forms.DockStyle.Top;
            this.mainTextBox.Location = new System.Drawing.Point(0, 0);
            this.mainTextBox.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.mainTextBox.Multiline = true;
            this.mainTextBox.Name = "mainTextBox";
            this.mainTextBox.Size = new System.Drawing.Size(1180, 190);
            this.mainTextBox.TabIndex = 1;
            // 
            // mainRichTextBox
            // 
            this.mainRichTextBox.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.mainRichTextBox.Location = new System.Drawing.Point(0, 199);
            this.mainRichTextBox.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.mainRichTextBox.Name = "mainRichTextBox";
            this.mainRichTextBox.Size = new System.Drawing.Size(1180, 207);
            this.mainRichTextBox.TabIndex = 0;
            this.mainRichTextBox.Text = "";
            // 
            // settingsPanel
            // 
            this.settingsPanel.Controls.Add(this.buttonTimeRange);
            this.settingsPanel.Controls.Add(this.textBoxSecondTime);
            this.settingsPanel.Controls.Add(this.textBoxFirstTime);
            this.settingsPanel.Controls.Add(this.label1);
            this.settingsPanel.Controls.Add(this.labelDataTime);
            this.settingsPanel.Controls.Add(this.formSearchbutton);
            this.settingsPanel.Controls.Add(this.signatureSearchButton);
            this.settingsPanel.Controls.Add(this.addButton);
            this.settingsPanel.Controls.Add(this.inclusionButton);
            this.settingsPanel.Controls.Add(this.openFileButton);
            this.settingsPanel.Controls.Add(this.signatureLabel);
            this.settingsPanel.Controls.Add(this.comboBoxSignature);
            this.settingsPanel.Dock = System.Windows.Forms.DockStyle.Top;
            this.settingsPanel.Location = new System.Drawing.Point(0, 0);
            this.settingsPanel.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.settingsPanel.Name = "settingsPanel";
            this.settingsPanel.Size = new System.Drawing.Size(1180, 159);
            this.settingsPanel.TabIndex = 0;
            // 
            // buttonTimeRange
            // 
            this.buttonTimeRange.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonTimeRange.Location = new System.Drawing.Point(944, 107);
            this.buttonTimeRange.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonTimeRange.Name = "buttonTimeRange";
            this.buttonTimeRange.Size = new System.Drawing.Size(224, 41);
            this.buttonTimeRange.TabIndex = 13;
            this.buttonTimeRange.Text = "Time range";
            this.buttonTimeRange.UseVisualStyleBackColor = true;
            this.buttonTimeRange.Click += new System.EventHandler(this.buttonTimeRange_Click);
            // 
            // textBoxSecondTime
            // 
            this.textBoxSecondTime.Location = new System.Drawing.Point(667, 22);
            this.textBoxSecondTime.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.textBoxSecondTime.Name = "textBoxSecondTime";
            this.textBoxSecondTime.Size = new System.Drawing.Size(153, 22);
            this.textBoxSecondTime.TabIndex = 12;
            // 
            // textBoxFirstTime
            // 
            this.textBoxFirstTime.Location = new System.Drawing.Point(461, 23);
            this.textBoxFirstTime.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.textBoxFirstTime.Name = "textBoxFirstTime";
            this.textBoxFirstTime.Size = new System.Drawing.Size(155, 22);
            this.textBoxFirstTime.TabIndex = 11;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(625, 22);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(31, 27);
            this.label1.TabIndex = 10;
            this.label1.Text = "to";
            // 
            // labelDataTime
            // 
            this.labelDataTime.AutoSize = true;
            this.labelDataTime.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelDataTime.Location = new System.Drawing.Point(243, 22);
            this.labelDataTime.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labelDataTime.Name = "labelDataTime";
            this.labelDataTime.Size = new System.Drawing.Size(201, 27);
            this.labelDataTime.TabIndex = 9;
            this.labelDataTime.Text = "Choose a time from";
            // 
            // formSearchbutton
            // 
            this.formSearchbutton.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.formSearchbutton.Location = new System.Drawing.Point(480, 107);
            this.formSearchbutton.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.formSearchbutton.Name = "formSearchbutton";
            this.formSearchbutton.Size = new System.Drawing.Size(224, 41);
            this.formSearchbutton.TabIndex = 6;
            this.formSearchbutton.Text = "Form search";
            this.formSearchbutton.UseVisualStyleBackColor = true;
            this.formSearchbutton.Click += new System.EventHandler(this.formSearchbutton_Click);
            // 
            // signatureSearchButton
            // 
            this.signatureSearchButton.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.signatureSearchButton.Location = new System.Drawing.Point(248, 107);
            this.signatureSearchButton.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.signatureSearchButton.Name = "signatureSearchButton";
            this.signatureSearchButton.Size = new System.Drawing.Size(224, 41);
            this.signatureSearchButton.TabIndex = 5;
            this.signatureSearchButton.Text = "Signature search";
            this.signatureSearchButton.UseVisualStyleBackColor = true;
            this.signatureSearchButton.Click += new System.EventHandler(this.signatureSearchButton_Click);
            // 
            // addButton
            // 
            this.addButton.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.addButton.Location = new System.Drawing.Point(16, 107);
            this.addButton.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.addButton.Name = "addButton";
            this.addButton.Size = new System.Drawing.Size(224, 41);
            this.addButton.TabIndex = 4;
            this.addButton.Text = "Add";
            this.addButton.UseVisualStyleBackColor = true;
            this.addButton.Click += new System.EventHandler(this.addButton_Click);
            // 
            // inclusionButton
            // 
            this.inclusionButton.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.inclusionButton.Location = new System.Drawing.Point(712, 107);
            this.inclusionButton.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.inclusionButton.Name = "inclusionButton";
            this.inclusionButton.Size = new System.Drawing.Size(224, 41);
            this.inclusionButton.TabIndex = 3;
            this.inclusionButton.Text = "Highlight unclusions";
            this.inclusionButton.UseVisualStyleBackColor = true;
            this.inclusionButton.Click += new System.EventHandler(this.inclusionButton_Click);
            // 
            // openFileButton
            // 
            this.openFileButton.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.openFileButton.Location = new System.Drawing.Point(1044, 7);
            this.openFileButton.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.openFileButton.Name = "openFileButton";
            this.openFileButton.Size = new System.Drawing.Size(124, 46);
            this.openFileButton.TabIndex = 2;
            this.openFileButton.Text = "Open file";
            this.openFileButton.UseVisualStyleBackColor = true;
            this.openFileButton.Click += new System.EventHandler(this.openFileButton_Click);
            // 
            // signatureLabel
            // 
            this.signatureLabel.AutoSize = true;
            this.signatureLabel.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.signatureLabel.Location = new System.Drawing.Point(16, 34);
            this.signatureLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.signatureLabel.Name = "signatureLabel";
            this.signatureLabel.Size = new System.Drawing.Size(102, 27);
            this.signatureLabel.TabIndex = 1;
            this.signatureLabel.Text = "Signature";
            // 
            // comboBoxSignature
            // 
            this.comboBoxSignature.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.comboBoxSignature.FormattingEnabled = true;
            this.comboBoxSignature.Location = new System.Drawing.Point(16, 64);
            this.comboBoxSignature.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.comboBoxSignature.Name = "comboBoxSignature";
            this.comboBoxSignature.Size = new System.Drawing.Size(223, 35);
            this.comboBoxSignature.TabIndex = 0;
            // 
            // ParssingForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1180, 572);
            this.Controls.Add(this.mainPanel);
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "ParssingForm";
            this.Text = "ParssingForm";
            this.mainPanel.ResumeLayout(false);
            this.textPanel.ResumeLayout(false);
            this.textPanel.PerformLayout();
            this.settingsPanel.ResumeLayout(false);
            this.settingsPanel.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel mainPanel;
        private System.Windows.Forms.Panel textPanel;
        private System.Windows.Forms.TextBox mainTextBox;
        private System.Windows.Forms.RichTextBox mainRichTextBox;
        private System.Windows.Forms.Panel settingsPanel;
        private System.Windows.Forms.Button inclusionButton;
        private System.Windows.Forms.Button openFileButton;
        private System.Windows.Forms.Label signatureLabel;
        private System.Windows.Forms.ComboBox comboBoxSignature;
        private System.Windows.Forms.Button addButton;
        private System.Windows.Forms.Button signatureSearchButton;
        private System.Windows.Forms.Button formSearchbutton;
        private System.Windows.Forms.Label labelDataTime;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBoxSecondTime;
        private System.Windows.Forms.TextBox textBoxFirstTime;
        private System.Windows.Forms.Button buttonTimeRange;
    }
}