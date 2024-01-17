
namespace Lab1.Part2._1
{
    partial class LoginForm
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
            this.MainPanel = new System.Windows.Forms.Panel();
            this.surnamePanel = new System.Windows.Forms.Label();
            this.namePanel = new System.Windows.Forms.Label();
            this.sendButton = new System.Windows.Forms.Button();
            this.surnameField = new System.Windows.Forms.TextBox();
            this.nameField = new System.Windows.Forms.TextBox();
            this.userPictureBox = new System.Windows.Forms.PictureBox();
            this.panel2 = new System.Windows.Forms.Panel();
            this.closeButton = new System.Windows.Forms.Label();
            this.autorizationPanel = new System.Windows.Forms.Label();
            this.MainPanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.userPictureBox)).BeginInit();
            this.panel2.SuspendLayout();
            this.SuspendLayout();
            // 
            // MainPanel
            // 
            this.MainPanel.BackColor = System.Drawing.Color.Maroon;
            this.MainPanel.Controls.Add(this.surnamePanel);
            this.MainPanel.Controls.Add(this.namePanel);
            this.MainPanel.Controls.Add(this.sendButton);
            this.MainPanel.Controls.Add(this.surnameField);
            this.MainPanel.Controls.Add(this.nameField);
            this.MainPanel.Controls.Add(this.userPictureBox);
            this.MainPanel.Controls.Add(this.panel2);
            this.MainPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.MainPanel.Location = new System.Drawing.Point(0, 0);
            this.MainPanel.Name = "MainPanel";
            this.MainPanel.Size = new System.Drawing.Size(500, 465);
            this.MainPanel.TabIndex = 0;
            this.MainPanel.MouseDown += new System.Windows.Forms.MouseEventHandler(this.MainPanel_MouseDown);
            this.MainPanel.MouseMove += new System.Windows.Forms.MouseEventHandler(this.MainPanel_MouseMove);
            // 
            // surnamePanel
            // 
            this.surnamePanel.AutoSize = true;
            this.surnamePanel.Font = new System.Drawing.Font("Showcard Gothic", 26.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.surnamePanel.Location = new System.Drawing.Point(3, 272);
            this.surnamePanel.Name = "surnamePanel";
            this.surnamePanel.Size = new System.Drawing.Size(178, 44);
            this.surnamePanel.TabIndex = 7;
            this.surnamePanel.Text = "Surname";
            this.surnamePanel.MouseDown += new System.Windows.Forms.MouseEventHandler(this.surnamePanel_MouseDown);
            this.surnamePanel.MouseMove += new System.Windows.Forms.MouseEventHandler(this.surnamePanel_MouseMove);
            // 
            // namePanel
            // 
            this.namePanel.AutoSize = true;
            this.namePanel.Font = new System.Drawing.Font("Showcard Gothic", 26.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.namePanel.Location = new System.Drawing.Point(12, 205);
            this.namePanel.Name = "namePanel";
            this.namePanel.Size = new System.Drawing.Size(111, 44);
            this.namePanel.TabIndex = 6;
            this.namePanel.Text = "Name";
            this.namePanel.MouseDown += new System.Windows.Forms.MouseEventHandler(this.namePanel_MouseDown);
            this.namePanel.MouseMove += new System.Windows.Forms.MouseEventHandler(this.namePanel_MouseMove);
            // 
            // sendButton
            // 
            this.sendButton.BackColor = System.Drawing.Color.White;
            this.sendButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.sendButton.FlatAppearance.BorderSize = 0;
            this.sendButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.DarkGray;
            this.sendButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.DarkGray;
            this.sendButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.sendButton.Font = new System.Drawing.Font("Showcard Gothic", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.sendButton.Location = new System.Drawing.Point(112, 371);
            this.sendButton.Name = "sendButton";
            this.sendButton.Size = new System.Drawing.Size(201, 42);
            this.sendButton.TabIndex = 5;
            this.sendButton.Text = "Send";
            this.sendButton.UseVisualStyleBackColor = false;
            this.sendButton.Click += new System.EventHandler(this.sendButton_Click);
            // 
            // surnameField
            // 
            this.surnameField.Font = new System.Drawing.Font("Times New Roman", 27.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.surnameField.Location = new System.Drawing.Point(208, 273);
            this.surnameField.Name = "surnameField";
            this.surnameField.Size = new System.Drawing.Size(257, 50);
            this.surnameField.TabIndex = 4;
            // 
            // nameField
            // 
            this.nameField.Font = new System.Drawing.Font("Times New Roman", 28.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.nameField.Location = new System.Drawing.Point(208, 206);
            this.nameField.Name = "nameField";
            this.nameField.Size = new System.Drawing.Size(257, 51);
            this.nameField.TabIndex = 2;
            // 
            // userPictureBox
            // 
            this.userPictureBox.BackColor = System.Drawing.Color.Transparent;
            this.userPictureBox.Image = global::Lab1.Part2._1.Properties.Resources.user;
            this.userPictureBox.InitialImage = global::Lab1.Part2._1.Properties.Resources.user;
            this.userPictureBox.Location = new System.Drawing.Point(12, 106);
            this.userPictureBox.Name = "userPictureBox";
            this.userPictureBox.Size = new System.Drawing.Size(73, 64);
            this.userPictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.userPictureBox.TabIndex = 1;
            this.userPictureBox.TabStop = false;
            this.userPictureBox.MouseDown += new System.Windows.Forms.MouseEventHandler(this.userPictureBox_MouseDown);
            this.userPictureBox.MouseMove += new System.Windows.Forms.MouseEventHandler(this.userPictureBox_MouseMove);
            // 
            // panel2
            // 
            this.panel2.BackColor = System.Drawing.Color.Black;
            this.panel2.Controls.Add(this.closeButton);
            this.panel2.Controls.Add(this.autorizationPanel);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel2.Location = new System.Drawing.Point(0, 0);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(500, 100);
            this.panel2.TabIndex = 0;
            // 
            // closeButton
            // 
            this.closeButton.AutoSize = true;
            this.closeButton.BackColor = System.Drawing.Color.Transparent;
            this.closeButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.closeButton.Dock = System.Windows.Forms.DockStyle.Right;
            this.closeButton.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.closeButton.Location = new System.Drawing.Point(486, 0);
            this.closeButton.Name = "closeButton";
            this.closeButton.Size = new System.Drawing.Size(14, 15);
            this.closeButton.TabIndex = 1;
            this.closeButton.Text = "X";
            this.closeButton.Click += new System.EventHandler(this.closeButton_Click);
            this.closeButton.MouseEnter += new System.EventHandler(this.closeButton_MouseEnter);
            this.closeButton.MouseLeave += new System.EventHandler(this.closeButton_MouseLeave);
            // 
            // autorizationPanel
            // 
            this.autorizationPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.autorizationPanel.Font = new System.Drawing.Font("Showcard Gothic", 33.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.autorizationPanel.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.autorizationPanel.Location = new System.Drawing.Point(0, 0);
            this.autorizationPanel.Name = "autorizationPanel";
            this.autorizationPanel.Size = new System.Drawing.Size(500, 100);
            this.autorizationPanel.TabIndex = 0;
            this.autorizationPanel.Text = "Authorization";
            this.autorizationPanel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.autorizationPanel.MouseDown += new System.Windows.Forms.MouseEventHandler(this.autorizationPanel_MouseDown);
            this.autorizationPanel.MouseMove += new System.Windows.Forms.MouseEventHandler(this.autorizationPanel_MouseMove);
            // 
            // LoginForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(500, 465);
            this.Controls.Add(this.MainPanel);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "LoginForm";
            this.Text = "LoginForm";
            this.MainPanel.ResumeLayout(false);
            this.MainPanel.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.userPictureBox)).EndInit();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel MainPanel;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Label closeButton;
        private System.Windows.Forms.Label autorizationPanel;
        private System.Windows.Forms.PictureBox userPictureBox;
        private System.Windows.Forms.Button sendButton;
        private System.Windows.Forms.TextBox surnameField;
        private System.Windows.Forms.TextBox nameField;
        private System.Windows.Forms.Label surnamePanel;
        private System.Windows.Forms.Label namePanel;
    }
}