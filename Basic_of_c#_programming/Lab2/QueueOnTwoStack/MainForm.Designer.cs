
namespace QueueOnTwoStack
{
    partial class MainForm
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
            this.labelResize = new System.Windows.Forms.Label();
            this.buttonResize = new System.Windows.Forms.Button();
            this.numericUpDownsizeQueue = new System.Windows.Forms.NumericUpDown();
            this.buttonDequeue = new System.Windows.Forms.Button();
            this.buttonEqueue = new System.Windows.Forms.Button();
            this.textBoxDequeue = new System.Windows.Forms.TextBox();
            this.labelDequeue = new System.Windows.Forms.Label();
            this.labelEnqueue = new System.Windows.Forms.Label();
            this.textBoxEnqueue = new System.Windows.Forms.TextBox();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.mainPanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownsizeQueue)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // mainPanel
            // 
            this.mainPanel.Controls.Add(this.labelResize);
            this.mainPanel.Controls.Add(this.buttonResize);
            this.mainPanel.Controls.Add(this.numericUpDownsizeQueue);
            this.mainPanel.Controls.Add(this.buttonDequeue);
            this.mainPanel.Controls.Add(this.buttonEqueue);
            this.mainPanel.Controls.Add(this.textBoxDequeue);
            this.mainPanel.Controls.Add(this.labelDequeue);
            this.mainPanel.Controls.Add(this.labelEnqueue);
            this.mainPanel.Controls.Add(this.textBoxEnqueue);
            this.mainPanel.Controls.Add(this.dataGridView1);
            this.mainPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.mainPanel.Location = new System.Drawing.Point(0, 0);
            this.mainPanel.Name = "mainPanel";
            this.mainPanel.Size = new System.Drawing.Size(800, 236);
            this.mainPanel.TabIndex = 0;
            // 
            // labelResize
            // 
            this.labelResize.AutoSize = true;
            this.labelResize.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelResize.Location = new System.Drawing.Point(317, 31);
            this.labelResize.Name = "labelResize";
            this.labelResize.Size = new System.Drawing.Size(183, 22);
            this.labelResize.TabIndex = 10;
            this.labelResize.Text = "Change array length:";
            // 
            // buttonResize
            // 
            this.buttonResize.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonResize.Location = new System.Drawing.Point(321, 113);
            this.buttonResize.Name = "buttonResize";
            this.buttonResize.Size = new System.Drawing.Size(165, 39);
            this.buttonResize.TabIndex = 9;
            this.buttonResize.Text = "Resize";
            this.buttonResize.UseVisualStyleBackColor = true;
            this.buttonResize.Click += new System.EventHandler(this.buttonResize_Click);
            // 
            // numericUpDownsizeQueue
            // 
            this.numericUpDownsizeQueue.Location = new System.Drawing.Point(345, 82);
            this.numericUpDownsizeQueue.Name = "numericUpDownsizeQueue";
            this.numericUpDownsizeQueue.Size = new System.Drawing.Size(120, 20);
            this.numericUpDownsizeQueue.TabIndex = 8;
            this.numericUpDownsizeQueue.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            // 
            // buttonDequeue
            // 
            this.buttonDequeue.Font = new System.Drawing.Font("Times New Roman", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonDequeue.Location = new System.Drawing.Point(556, 114);
            this.buttonDequeue.Name = "buttonDequeue";
            this.buttonDequeue.Size = new System.Drawing.Size(165, 39);
            this.buttonDequeue.TabIndex = 7;
            this.buttonDequeue.Text = "Dequeue";
            this.buttonDequeue.UseVisualStyleBackColor = true;
            this.buttonDequeue.Click += new System.EventHandler(this.buttonDequeue_Click);
            // 
            // buttonEqueue
            // 
            this.buttonEqueue.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonEqueue.Location = new System.Drawing.Point(68, 112);
            this.buttonEqueue.Name = "buttonEqueue";
            this.buttonEqueue.Size = new System.Drawing.Size(165, 40);
            this.buttonEqueue.TabIndex = 6;
            this.buttonEqueue.Text = "Enqueue";
            this.buttonEqueue.UseVisualStyleBackColor = true;
            this.buttonEqueue.Click += new System.EventHandler(this.buttonEqueue_Click);
            // 
            // textBoxDequeue
            // 
            this.textBoxDequeue.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.textBoxDequeue.Location = new System.Drawing.Point(556, 56);
            this.textBoxDequeue.Multiline = true;
            this.textBoxDequeue.Name = "textBoxDequeue";
            this.textBoxDequeue.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.textBoxDequeue.Size = new System.Drawing.Size(165, 46);
            this.textBoxDequeue.TabIndex = 5;
            // 
            // labelDequeue
            // 
            this.labelDequeue.AutoSize = true;
            this.labelDequeue.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelDequeue.Location = new System.Drawing.Point(559, 31);
            this.labelDequeue.Name = "labelDequeue";
            this.labelDequeue.Size = new System.Drawing.Size(162, 22);
            this.labelDequeue.TabIndex = 4;
            this.labelDequeue.Text = "Extracted number:";
            // 
            // labelEnqueue
            // 
            this.labelEnqueue.AutoSize = true;
            this.labelEnqueue.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelEnqueue.Location = new System.Drawing.Point(64, 31);
            this.labelEnqueue.Name = "labelEnqueue";
            this.labelEnqueue.Size = new System.Drawing.Size(128, 22);
            this.labelEnqueue.TabIndex = 3;
            this.labelEnqueue.Text = "Enter number:";
            // 
            // textBoxEnqueue
            // 
            this.textBoxEnqueue.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.textBoxEnqueue.Location = new System.Drawing.Point(68, 56);
            this.textBoxEnqueue.Multiline = true;
            this.textBoxEnqueue.Name = "textBoxEnqueue";
            this.textBoxEnqueue.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.textBoxEnqueue.Size = new System.Drawing.Size(165, 46);
            this.textBoxEnqueue.TabIndex = 1;
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.dataGridView1.Location = new System.Drawing.Point(0, 160);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.Size = new System.Drawing.Size(800, 76);
            this.dataGridView1.TabIndex = 0;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 236);
            this.Controls.Add(this.mainPanel);
            this.Name = "MainForm";
            this.Text = "Form1";
            this.mainPanel.ResumeLayout(false);
            this.mainPanel.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownsizeQueue)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel mainPanel;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Label labelDequeue;
        private System.Windows.Forms.Label labelEnqueue;
        private System.Windows.Forms.TextBox textBoxEnqueue;
        private System.Windows.Forms.Button buttonDequeue;
        private System.Windows.Forms.Button buttonEqueue;
        private System.Windows.Forms.TextBox textBoxDequeue;
        private System.Windows.Forms.Label labelResize;
        private System.Windows.Forms.Button buttonResize;
        private System.Windows.Forms.NumericUpDown numericUpDownsizeQueue;
    }
}

