
namespace Lab2Part2._2
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
            this.panel1 = new System.Windows.Forms.Panel();
            this.valueFrequency = new System.Windows.Forms.NumericUpDown();
            this.labelFreguency = new System.Windows.Forms.Label();
            this.buttonCreate = new System.Windows.Forms.Button();
            this.arrayLength = new System.Windows.Forms.NumericUpDown();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.radioButtonByHand = new System.Windows.Forms.RadioButton();
            this.radioButtonRandom = new System.Windows.Forms.RadioButton();
            this.arraySizeLabel = new System.Windows.Forms.Label();
            this.checkBoxFrequencyTimeElement = new System.Windows.Forms.CheckBox();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.valueFrequency)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.arrayLength)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.panel1.Controls.Add(this.checkBoxFrequencyTimeElement);
            this.panel1.Controls.Add(this.valueFrequency);
            this.panel1.Controls.Add(this.labelFreguency);
            this.panel1.Controls.Add(this.buttonCreate);
            this.panel1.Controls.Add(this.arrayLength);
            this.panel1.Controls.Add(this.groupBox1);
            this.panel1.Controls.Add(this.arraySizeLabel);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(476, 213);
            this.panel1.TabIndex = 0;
            // 
            // valueFrequency
            // 
            this.valueFrequency.Location = new System.Drawing.Point(22, 87);
            this.valueFrequency.Name = "valueFrequency";
            this.valueFrequency.Size = new System.Drawing.Size(70, 20);
            this.valueFrequency.TabIndex = 7;
            this.valueFrequency.Value = new decimal(new int[] {
            2,
            0,
            0,
            0});
            // 
            // labelFreguency
            // 
            this.labelFreguency.AutoSize = true;
            this.labelFreguency.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelFreguency.Location = new System.Drawing.Point(18, 55);
            this.labelFreguency.Name = "labelFreguency";
            this.labelFreguency.Size = new System.Drawing.Size(185, 22);
            this.labelFreguency.TabIndex = 6;
            this.labelFreguency.Text = "With what frequency:";
            // 
            // buttonCreate
            // 
            this.buttonCreate.Font = new System.Drawing.Font("Times New Roman", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonCreate.Location = new System.Drawing.Point(122, 165);
            this.buttonCreate.Name = "buttonCreate";
            this.buttonCreate.Size = new System.Drawing.Size(204, 35);
            this.buttonCreate.TabIndex = 5;
            this.buttonCreate.Text = "create";
            this.buttonCreate.UseVisualStyleBackColor = true;
            this.buttonCreate.Click += new System.EventHandler(this.buttonCreate_Click);
            // 
            // arrayLength
            // 
            this.arrayLength.Location = new System.Drawing.Point(22, 32);
            this.arrayLength.Maximum = new decimal(new int[] {
            65000,
            0,
            0,
            0});
            this.arrayLength.Name = "arrayLength";
            this.arrayLength.Size = new System.Drawing.Size(70, 20);
            this.arrayLength.TabIndex = 4;
            this.arrayLength.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.radioButtonByHand);
            this.groupBox1.Controls.Add(this.radioButtonRandom);
            this.groupBox1.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.groupBox1.Location = new System.Drawing.Point(273, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(200, 100);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "How to fill array:";
            // 
            // radioButtonByHand
            // 
            this.radioButtonByHand.AutoSize = true;
            this.radioButtonByHand.Location = new System.Drawing.Point(7, 61);
            this.radioButtonByHand.Name = "radioButtonByHand";
            this.radioButtonByHand.Size = new System.Drawing.Size(88, 25);
            this.radioButtonByHand.TabIndex = 1;
            this.radioButtonByHand.TabStop = true;
            this.radioButtonByHand.Text = "by hand";
            this.radioButtonByHand.UseVisualStyleBackColor = true;
            this.radioButtonByHand.CheckedChanged += new System.EventHandler(this.radioButtonByHand_CheckedChanged);
            // 
            // radioButtonRandom
            // 
            this.radioButtonRandom.AutoSize = true;
            this.radioButtonRandom.Location = new System.Drawing.Point(7, 29);
            this.radioButtonRandom.Name = "radioButtonRandom";
            this.radioButtonRandom.Size = new System.Drawing.Size(85, 25);
            this.radioButtonRandom.TabIndex = 0;
            this.radioButtonRandom.TabStop = true;
            this.radioButtonRandom.Text = "random";
            this.radioButtonRandom.UseVisualStyleBackColor = true;
            this.radioButtonRandom.CheckedChanged += new System.EventHandler(this.radioButtonRandom_CheckedChanged);
            // 
            // arraySizeLabel
            // 
            this.arraySizeLabel.AutoSize = true;
            this.arraySizeLabel.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.arraySizeLabel.Location = new System.Drawing.Point(18, 7);
            this.arraySizeLabel.Name = "arraySizeLabel";
            this.arraySizeLabel.Size = new System.Drawing.Size(166, 22);
            this.arraySizeLabel.TabIndex = 0;
            this.arraySizeLabel.Text = "Enter array length:";
            // 
            // checkBoxFrequencyTimeElement
            // 
            this.checkBoxFrequencyTimeElement.AutoSize = true;
            this.checkBoxFrequencyTimeElement.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.checkBoxFrequencyTimeElement.Location = new System.Drawing.Point(22, 118);
            this.checkBoxFrequencyTimeElement.Name = "checkBoxFrequencyTimeElement";
            this.checkBoxFrequencyTimeElement.Size = new System.Drawing.Size(347, 26);
            this.checkBoxFrequencyTimeElement.TabIndex = 8;
            this.checkBoxFrequencyTimeElement.Text = "Form an array with a given frequency?";
            this.checkBoxFrequencyTimeElement.UseVisualStyleBackColor = true;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(476, 213);
            this.Controls.Add(this.panel1);
            this.Name = "MainForm";
            this.Text = "Form1";
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.valueFrequency)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.arrayLength)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton radioButtonByHand;
        private System.Windows.Forms.RadioButton radioButtonRandom;
        private System.Windows.Forms.Label arraySizeLabel;
        private System.Windows.Forms.NumericUpDown arrayLength;
        private System.Windows.Forms.Button buttonCreate;
        private System.Windows.Forms.NumericUpDown valueFrequency;
        private System.Windows.Forms.Label labelFreguency;
        private System.Windows.Forms.CheckBox checkBoxFrequencyTimeElement;
    }
}

