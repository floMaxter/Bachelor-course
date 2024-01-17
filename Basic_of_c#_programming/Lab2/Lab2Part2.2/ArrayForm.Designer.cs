
namespace Lab2Part2._2
{
    partial class ArrayForm
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
            this.panel1 = new System.Windows.Forms.Panel();
            this.labelSuggestionToFill = new System.Windows.Forms.Label();
            this.buttonSend = new System.Windows.Forms.Button();
            this.checkBoxTimer = new System.Windows.Forms.CheckBox();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.textBoxFillingType = new System.Windows.Forms.TextBox();
            this.textBoxLength = new System.Windows.Forms.TextBox();
            this.labelFilling = new System.Windows.Forms.Label();
            this.labelArrayLength = new System.Windows.Forms.Label();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.panel1.Controls.Add(this.labelSuggestionToFill);
            this.panel1.Controls.Add(this.buttonSend);
            this.panel1.Controls.Add(this.checkBoxTimer);
            this.panel1.Controls.Add(this.dataGridView1);
            this.panel1.Controls.Add(this.textBoxFillingType);
            this.panel1.Controls.Add(this.textBoxLength);
            this.panel1.Controls.Add(this.labelFilling);
            this.panel1.Controls.Add(this.labelArrayLength);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(800, 220);
            this.panel1.TabIndex = 0;
            // 
            // labelSuggestionToFill
            // 
            this.labelSuggestionToFill.AutoSize = true;
            this.labelSuggestionToFill.Font = new System.Drawing.Font("Times New Roman", 20.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelSuggestionToFill.Location = new System.Drawing.Point(312, 96);
            this.labelSuggestionToFill.Name = "labelSuggestionToFill";
            this.labelSuggestionToFill.Size = new System.Drawing.Size(179, 31);
            this.labelSuggestionToFill.TabIndex = 7;
            this.labelSuggestionToFill.Text = "Fill the array:";
            // 
            // buttonSend
            // 
            this.buttonSend.Font = new System.Drawing.Font("Times New Roman", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonSend.Location = new System.Drawing.Point(548, 12);
            this.buttonSend.Name = "buttonSend";
            this.buttonSend.Size = new System.Drawing.Size(226, 79);
            this.buttonSend.TabIndex = 6;
            this.buttonSend.Text = "Send";
            this.buttonSend.UseVisualStyleBackColor = true;
            this.buttonSend.Click += new System.EventHandler(this.buttonSend_Click);
            // 
            // checkBoxTimer
            // 
            this.checkBoxTimer.AutoSize = true;
            this.checkBoxTimer.Checked = true;
            this.checkBoxTimer.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBoxTimer.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.checkBoxTimer.Location = new System.Drawing.Point(340, 12);
            this.checkBoxTimer.Name = "checkBoxTimer";
            this.checkBoxTimer.Size = new System.Drawing.Size(121, 25);
            this.checkBoxTimer.TabIndex = 5;
            this.checkBoxTimer.Text = "Enable timer";
            this.checkBoxTimer.UseVisualStyleBackColor = true;
            // 
            // dataGridView1
            // 
            this.dataGridView1.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.AllCellsExceptHeader;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.dataGridView1.Location = new System.Drawing.Point(0, 146);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 51;
            this.dataGridView1.Size = new System.Drawing.Size(800, 74);
            this.dataGridView1.TabIndex = 4;
            // 
            // textBoxFillingType
            // 
            this.textBoxFillingType.Enabled = false;
            this.textBoxFillingType.Font = new System.Drawing.Font("Times New Roman", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.textBoxFillingType.Location = new System.Drawing.Point(190, 65);
            this.textBoxFillingType.Multiline = true;
            this.textBoxFillingType.Name = "textBoxFillingType";
            this.textBoxFillingType.Size = new System.Drawing.Size(116, 31);
            this.textBoxFillingType.TabIndex = 3;
            // 
            // textBoxLength
            // 
            this.textBoxLength.Enabled = false;
            this.textBoxLength.Font = new System.Drawing.Font("Times New Roman", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.textBoxLength.Location = new System.Drawing.Point(190, 16);
            this.textBoxLength.Multiline = true;
            this.textBoxLength.Name = "textBoxLength";
            this.textBoxLength.Size = new System.Drawing.Size(116, 31);
            this.textBoxLength.TabIndex = 2;
            // 
            // labelFilling
            // 
            this.labelFilling.AutoSize = true;
            this.labelFilling.Font = new System.Drawing.Font("Times New Roman", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelFilling.Location = new System.Drawing.Point(12, 65);
            this.labelFilling.Name = "labelFilling";
            this.labelFilling.Size = new System.Drawing.Size(116, 24);
            this.labelFilling.TabIndex = 1;
            this.labelFilling.Text = "Filling type:";
            // 
            // labelArrayLength
            // 
            this.labelArrayLength.AutoSize = true;
            this.labelArrayLength.Font = new System.Drawing.Font("Times New Roman", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelArrayLength.Location = new System.Drawing.Point(12, 19);
            this.labelArrayLength.Name = "labelArrayLength";
            this.labelArrayLength.Size = new System.Drawing.Size(129, 24);
            this.labelArrayLength.TabIndex = 0;
            this.labelArrayLength.Text = "Array length:";
            // 
            // ArrayForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 220);
            this.Controls.Add(this.panel1);
            this.Name = "ArrayForm";
            this.Text = "arrayForm";
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label labelArrayLength;
        private System.Windows.Forms.TextBox textBoxFillingType;
        private System.Windows.Forms.TextBox textBoxLength;
        private System.Windows.Forms.Label labelFilling;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.CheckBox checkBoxTimer;
        private System.Windows.Forms.Button buttonSend;
        private System.Windows.Forms.Label labelSuggestionToFill;
    }
}