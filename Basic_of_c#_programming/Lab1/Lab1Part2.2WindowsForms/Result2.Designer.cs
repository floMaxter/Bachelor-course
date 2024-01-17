
namespace Lab1Part2._2WindowsForms
{
    partial class Result2
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
            this.ResultLabel = new System.Windows.Forms.Label();
            this.exitButton = new System.Windows.Forms.Button();
            this.resultPanel = new System.Windows.Forms.Panel();
            this.resultArea = new System.Windows.Forms.TextBox();
            this.amountArea = new System.Windows.Forms.Label();
            this.resultPanel.SuspendLayout();
            this.SuspendLayout();
            // 
            // ResultLabel
            // 
            this.ResultLabel.AutoSize = true;
            this.ResultLabel.Font = new System.Drawing.Font("Franklin Gothic Medium Cond", 32.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.ResultLabel.Location = new System.Drawing.Point(12, 22);
            this.ResultLabel.Name = "ResultLabel";
            this.ResultLabel.Size = new System.Drawing.Size(133, 50);
            this.ResultLabel.TabIndex = 0;
            this.ResultLabel.Text = "Result:";
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
            this.exitButton.Location = new System.Drawing.Point(866, 0);
            this.exitButton.Name = "exitButton";
            this.exitButton.Size = new System.Drawing.Size(29, 28);
            this.exitButton.TabIndex = 1;
            this.exitButton.Text = "X";
            this.exitButton.UseVisualStyleBackColor = false;
            this.exitButton.Click += new System.EventHandler(this.exitButton_Click);
            // 
            // resultPanel
            // 
            this.resultPanel.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.resultPanel.Controls.Add(this.amountArea);
            this.resultPanel.Controls.Add(this.resultArea);
            this.resultPanel.Controls.Add(this.exitButton);
            this.resultPanel.Controls.Add(this.ResultLabel);
            this.resultPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.resultPanel.Location = new System.Drawing.Point(0, 0);
            this.resultPanel.Name = "resultPanel";
            this.resultPanel.Size = new System.Drawing.Size(895, 462);
            this.resultPanel.TabIndex = 3;
            this.resultPanel.MouseDown += new System.Windows.Forms.MouseEventHandler(this.resultPanel_MouseDown);
            this.resultPanel.MouseMove += new System.Windows.Forms.MouseEventHandler(this.resultPanel_MouseMove);
            // 
            // resultArea
            // 
            this.resultArea.Font = new System.Drawing.Font("Franklin Gothic Medium Cond", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.resultArea.Location = new System.Drawing.Point(12, 106);
            this.resultArea.Multiline = true;
            this.resultArea.Name = "resultArea";
            this.resultArea.Size = new System.Drawing.Size(850, 85);
            this.resultArea.TabIndex = 2;
            // 
            // amountArea
            // 
            this.amountArea.AutoSize = true;
            this.amountArea.Font = new System.Drawing.Font("Franklin Gothic Medium Cond", 32.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.amountArea.Location = new System.Drawing.Point(163, 22);
            this.amountArea.Name = "amountArea";
            this.amountArea.Size = new System.Drawing.Size(144, 50);
            this.amountArea.TabIndex = 3;
            this.amountArea.Text = "amount";
            // 
            // Result2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(895, 462);
            this.Controls.Add(this.resultPanel);
            this.Name = "Result2";
            this.Text = "Result2";
            this.resultPanel.ResumeLayout(false);
            this.resultPanel.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label ResultLabel;
        private System.Windows.Forms.Button exitButton;
        private System.Windows.Forms.Panel resultPanel;
        private System.Windows.Forms.TextBox resultArea;
        private System.Windows.Forms.Label amountArea;
    }
}