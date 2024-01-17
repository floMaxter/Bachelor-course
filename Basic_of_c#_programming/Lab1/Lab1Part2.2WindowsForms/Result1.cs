using System;
using System.Windows.Forms;

namespace Lab1Part2._2WindowsForms
{
    public partial class Result1 : Form
    {
        private int number;
        private int valueA;
        private int counterEvenNumber;
        private int counterForA;
        public Result1(int number, int valueA)
        {
            this.number = number;
            this.valueA = valueA;
            this.counterEvenNumber = 0;
            this.counterForA = 0;
            InitializeComponent();

            functionForCounter();
            
            this.evenNumbersLabel.Text = counterEvenNumber.ToString();
            this.entryNumberLabel.Text = counterForA.ToString();
        }


        private void functionForCounter()
        {
            int temp = number;
            while (temp != 0)
            {
                int digitOfNumber = temp % 10;
                if (digitOfNumber == valueA)
                {
                    this.counterForA++;
                }
                if (digitOfNumber % 2 == 0)
                {
                    this.counterEvenNumber++;
                }
                temp /= 10;
            }
        }

        private void exitButton_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
