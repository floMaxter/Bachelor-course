
namespace Lab2Part2._2
{
    partial class ResultForm
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
            this.panelSumResult = new System.Windows.Forms.Panel();
            this.textBoxSomeThread = new System.Windows.Forms.TextBox();
            this.textBoxOneThread = new System.Windows.Forms.TextBox();
            this.labelSomeThread = new System.Windows.Forms.Label();
            this.labelOneThread = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.textBoxPair = new System.Windows.Forms.TextBox();
            this.textBoxSum = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.textBoxIndex = new System.Windows.Forms.TextBox();
            this.labelSum = new System.Windows.Forms.Label();
            this.panelSumResult.SuspendLayout();
            this.SuspendLayout();
            // 
            // panelSumResult
            // 
            this.panelSumResult.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.panelSumResult.Controls.Add(this.textBoxSomeThread);
            this.panelSumResult.Controls.Add(this.textBoxOneThread);
            this.panelSumResult.Controls.Add(this.labelSomeThread);
            this.panelSumResult.Controls.Add(this.labelOneThread);
            this.panelSumResult.Controls.Add(this.label2);
            this.panelSumResult.Controls.Add(this.textBoxPair);
            this.panelSumResult.Controls.Add(this.textBoxSum);
            this.panelSumResult.Controls.Add(this.label1);
            this.panelSumResult.Controls.Add(this.textBoxIndex);
            this.panelSumResult.Controls.Add(this.labelSum);
            this.panelSumResult.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panelSumResult.Location = new System.Drawing.Point(0, 0);
            this.panelSumResult.Name = "panelSumResult";
            this.panelSumResult.Size = new System.Drawing.Size(881, 391);
            this.panelSumResult.TabIndex = 0;
            // 
            // textBoxSomeThread
            // 
            this.textBoxSomeThread.Enabled = false;
            this.textBoxSomeThread.Location = new System.Drawing.Point(666, 140);
            this.textBoxSomeThread.Multiline = true;
            this.textBoxSomeThread.Name = "textBoxSomeThread";
            this.textBoxSomeThread.Size = new System.Drawing.Size(193, 30);
            this.textBoxSomeThread.TabIndex = 9;
            // 
            // textBoxOneThread
            // 
            this.textBoxOneThread.Enabled = false;
            this.textBoxOneThread.Location = new System.Drawing.Point(666, 51);
            this.textBoxOneThread.Multiline = true;
            this.textBoxOneThread.Name = "textBoxOneThread";
            this.textBoxOneThread.Size = new System.Drawing.Size(193, 30);
            this.textBoxOneThread.TabIndex = 8;
            // 
            // labelSomeThread
            // 
            this.labelSomeThread.AutoSize = true;
            this.labelSomeThread.Font = new System.Drawing.Font("Times New Roman", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelSomeThread.Location = new System.Drawing.Point(662, 99);
            this.labelSomeThread.Name = "labelSomeThread";
            this.labelSomeThread.Size = new System.Drawing.Size(197, 24);
            this.labelSomeThread.TabIndex = 7;
            this.labelSomeThread.Text = "Time in some thread:";
            // 
            // labelOneThread
            // 
            this.labelOneThread.AutoSize = true;
            this.labelOneThread.Font = new System.Drawing.Font("Times New Roman", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelOneThread.Location = new System.Drawing.Point(662, 22);
            this.labelOneThread.Name = "labelOneThread";
            this.labelOneThread.Size = new System.Drawing.Size(183, 24);
            this.labelOneThread.TabIndex = 6;
            this.labelOneThread.Text = "Time in one thread:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Times New Roman", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(12, 237);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(121, 24);
            this.label2.TabIndex = 5;
            this.label2.Text = "Pair by sign:";
            // 
            // textBoxPair
            // 
            this.textBoxPair.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.textBoxPair.Location = new System.Drawing.Point(16, 135);
            this.textBoxPair.Multiline = true;
            this.textBoxPair.Name = "textBoxPair";
            this.textBoxPair.Size = new System.Drawing.Size(577, 92);
            this.textBoxPair.TabIndex = 4;
            // 
            // textBoxSum
            // 
            this.textBoxSum.Enabled = false;
            this.textBoxSum.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.textBoxSum.Location = new System.Drawing.Point(16, 46);
            this.textBoxSum.Multiline = true;
            this.textBoxSum.Name = "textBoxSum";
            this.textBoxSum.Size = new System.Drawing.Size(577, 35);
            this.textBoxSum.TabIndex = 3;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Times New Roman", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(12, 84);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(568, 24);
            this.label1.TabIndex = 2;
            this.label1.Text = "Index of elements whose value is greater than the previous one:";
            // 
            // textBoxIndex
            // 
            this.textBoxIndex.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.textBoxIndex.Location = new System.Drawing.Point(16, 271);
            this.textBoxIndex.Multiline = true;
            this.textBoxIndex.Name = "textBoxIndex";
            this.textBoxIndex.Size = new System.Drawing.Size(577, 92);
            this.textBoxIndex.TabIndex = 1;
            // 
            // labelSum
            // 
            this.labelSum.AutoSize = true;
            this.labelSum.Font = new System.Drawing.Font("Times New Roman", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelSum.Location = new System.Drawing.Point(12, 9);
            this.labelSum.Name = "labelSum";
            this.labelSum.Size = new System.Drawing.Size(333, 24);
            this.labelSum.TabIndex = 0;
            this.labelSum.Text = "Double the sum of positive elements:";
            // 
            // ResultForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(881, 391);
            this.Controls.Add(this.panelSumResult);
            this.Name = "ResultForm";
            this.Text = "ResultForm";
            this.panelSumResult.ResumeLayout(false);
            this.panelSumResult.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panelSumResult;
        private System.Windows.Forms.TextBox textBoxIndex;
        private System.Windows.Forms.Label labelSum;
        private System.Windows.Forms.TextBox textBoxPair;
        private System.Windows.Forms.TextBox textBoxSum;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBoxSomeThread;
        private System.Windows.Forms.TextBox textBoxOneThread;
        private System.Windows.Forms.Label labelSomeThread;
        private System.Windows.Forms.Label labelOneThread;
        private System.Windows.Forms.Label label2;
    }
}