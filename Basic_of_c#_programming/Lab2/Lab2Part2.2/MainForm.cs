using System;
using System.Windows.Forms;

namespace Lab2Part2._2
{
    public partial class MainForm : Form
    {
        private bool randomFillign;
        private int arrLength;
        private int valFreq;
        public MainForm()
        {
            InitializeComponent();
        }

        private void radioButtonRandom_CheckedChanged(object sender, EventArgs e)
        {
            randomFillign = true;
            valueFrequency.Visible = true;
            labelFreguency.Visible = true;
            checkBoxFrequencyTimeElement.Visible = true;
        }

        private void radioButtonByHand_CheckedChanged(object sender, EventArgs e)
        {
            randomFillign = false;
            valueFrequency.Visible = false;
            labelFreguency.Visible = false;
            checkBoxFrequencyTimeElement.Visible = false;
        }

        private void buttonCreate_Click(object sender, EventArgs e)
        {
            try
            {
                arrLength = Convert.ToInt32(arrayLength.Value);
                valFreq = Convert.ToInt32(valueFrequency.Value);
                inputValidation();
                ArrayForm arrayForm = new ArrayForm(arrLength,
                                                    randomFillign,
                                                    valFreq);
                this.Hide();
                arrayForm.Show();
                if (randomFillign)
                {
                    arrayForm.fillRandomArray(checkBoxFrequencyTimeElement.Checked);
                }
            }
            catch(Exception ex)
            {
                MessageBox.Show("Error! " + ex.Message);
            }
        }

        private void inputValidation()
        {
            if(arrLength > 650 || arrLength < 1)
            {
                throw new Exception("Incorrect array length!");
            }
            if(valFreq <= 0)
            {
                throw new Exception("Incorrect fill frequency!");
            }
        }
    }
}
