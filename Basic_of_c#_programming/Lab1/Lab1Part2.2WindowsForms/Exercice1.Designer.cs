
namespace Lab1Part2._2WindowsForms
{
    partial class Exercice1
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
            this.AreaNumberA = new System.Windows.Forms.TextBox();
            this.EnterALabel = new System.Windows.Forms.Label();
            this.SendButton = new System.Windows.Forms.Button();
            this.NumberArea = new System.Windows.Forms.TextBox();
            this.exitButton = new System.Windows.Forms.Button();
            this.EnterNumberLabel = new System.Windows.Forms.Label();
            this.MainPanel.SuspendLayout();
            this.SuspendLayout();
            // 
            // MainPanel
            // 
            this.MainPanel.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.MainPanel.Controls.Add(this.AreaNumberA);
            this.MainPanel.Controls.Add(this.EnterALabel);
            this.MainPanel.Controls.Add(this.SendButton);
            this.MainPanel.Controls.Add(this.NumberArea);
            this.MainPanel.Controls.Add(this.exitButton);
            this.MainPanel.Controls.Add(this.EnterNumberLabel);
            this.MainPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.MainPanel.Location = new System.Drawing.Point(0, 0);
            this.MainPanel.Name = "MainPanel";
            this.MainPanel.Size = new System.Drawing.Size(430, 446);
            this.MainPanel.TabIndex = 0;
            this.MainPanel.MouseDown += new System.Windows.Forms.MouseEventHandler(this.MainPanel_MouseDown);
            this.MainPanel.MouseMove += new System.Windows.Forms.MouseEventHandler(this.MainPanel_MouseMove_1);
            // 
            // AreaNumberA
            // 
            this.AreaNumberA.Font = new System.Drawing.Font("Franklin Gothic Medium Cond", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.AreaNumberA.Location = new System.Drawing.Point(28, 255);
            this.AreaNumberA.Multiline = true;
            this.AreaNumberA.Name = "AreaNumberA";
            this.AreaNumberA.Size = new System.Drawing.Size(370, 43);
            this.AreaNumberA.TabIndex = 5;
            this.AreaNumberA.MouseDown += new System.Windows.Forms.MouseEventHandler(this.AreaNumberA_MouseDown);
            this.AreaNumberA.MouseMove += new System.Windows.Forms.MouseEventHandler(this.AreaNumberA_MouseMove);
            // 
            // EnterALabel
            // 
            this.EnterALabel.AutoSize = true;
            this.EnterALabel.Font = new System.Drawing.Font("Franklin Gothic Medium Cond", 27.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.EnterALabel.Location = new System.Drawing.Point(40, 191);
            this.EnterALabel.Name = "EnterALabel";
            this.EnterALabel.Size = new System.Drawing.Size(272, 43);
            this.EnterALabel.TabIndex = 4;
            this.EnterALabel.Text = "Enter number \"A\":";
            this.EnterALabel.MouseDown += new System.Windows.Forms.MouseEventHandler(this.EnterALabel_MouseDown);
            this.EnterALabel.MouseMove += new System.Windows.Forms.MouseEventHandler(this.EnterALabel_MouseMove);
            // 
            // SendButton
            // 
            this.SendButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.SendButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Black;
            this.SendButton.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.SendButton.Font = new System.Drawing.Font("Franklin Gothic Medium Cond", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.SendButton.Location = new System.Drawing.Point(110, 354);
            this.SendButton.Name = "SendButton";
            this.SendButton.Size = new System.Drawing.Size(215, 61);
            this.SendButton.TabIndex = 3;
            this.SendButton.Text = "Send";
            this.SendButton.UseVisualStyleBackColor = true;
            this.SendButton.Click += new System.EventHandler(this.SendButton_Click);
            // 
            // NumberArea
            // 
            this.NumberArea.Font = new System.Drawing.Font("Franklin Gothic Medium Cond", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.NumberArea.Location = new System.Drawing.Point(28, 121);
            this.NumberArea.Multiline = true;
            this.NumberArea.Name = "NumberArea";
            this.NumberArea.Size = new System.Drawing.Size(370, 43);
            this.NumberArea.TabIndex = 2;
            this.NumberArea.MouseDown += new System.Windows.Forms.MouseEventHandler(this.NumberArea_MouseDown);
            this.NumberArea.MouseMove += new System.Windows.Forms.MouseEventHandler(this.NumberArea_MouseMove);
            // 
            // exitButton
            // 
            this.exitButton.BackColor = System.Drawing.SystemColors.InactiveCaptionText;
            this.exitButton.FlatAppearance.BorderSize = 0;
            this.exitButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.exitButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Silver;
            this.exitButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.exitButton.Font = new System.Drawing.Font("Franklin Gothic Medium Cond", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.exitButton.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.exitButton.Location = new System.Drawing.Point(401, 0);
            this.exitButton.Name = "exitButton";
            this.exitButton.Size = new System.Drawing.Size(29, 28);
            this.exitButton.TabIndex = 1;
            this.exitButton.Text = "X";
            this.exitButton.UseVisualStyleBackColor = false;
            this.exitButton.Click += new System.EventHandler(this.exitButton_Click);
            // 
            // EnterNumberLabel
            // 
            this.EnterNumberLabel.AutoSize = true;
            this.EnterNumberLabel.Font = new System.Drawing.Font("Franklin Gothic Medium Cond", 27.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.EnterNumberLabel.Location = new System.Drawing.Point(40, 51);
            this.EnterNumberLabel.Name = "EnterNumberLabel";
            this.EnterNumberLabel.Size = new System.Drawing.Size(312, 43);
            this.EnterNumberLabel.TabIndex = 0;
            this.EnterNumberLabel.Text = "Enter natural number:";
            this.EnterNumberLabel.MouseDown += new System.Windows.Forms.MouseEventHandler(this.EnterNumberLabel_MouseDown);
            this.EnterNumberLabel.MouseMove += new System.Windows.Forms.MouseEventHandler(this.EnterNumberLabel_MouseMove);
            // 
            // Exercice1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(430, 446);
            this.Controls.Add(this.MainPanel);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "Exercice1";
            this.Text = "Exercice1";
            this.MainPanel.ResumeLayout(false);
            this.MainPanel.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel MainPanel;
        private System.Windows.Forms.Button SendButton;
        private System.Windows.Forms.TextBox NumberArea;
        private System.Windows.Forms.Button exitButton;
        private System.Windows.Forms.Label EnterNumberLabel;
        private System.Windows.Forms.TextBox AreaNumberA;
        private System.Windows.Forms.Label EnterALabel;
    }
}