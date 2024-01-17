using System;
using System.Drawing;
using System.Windows.Forms;

namespace Lab1Part2._2WindowsForms
{
    public partial class Result2 : Form
    {
        private int counterNumber;
        public Result2()
        {
            this.counterNumber = 0;
            String allNumbers = functionCounter();
            InitializeComponent();
            this.resultArea.Text = allNumbers;
            this.amountArea.Text = counterNumber.ToString();
        }

        private String functionCounter()
        {
            String allNumbers = String.Empty;
            for (int i = 1000; i < 9999; i++)
            {
                if ((i % 6) == 0 && (i % 27) == 0)
                {
                    if (conditionCheking(i))
                    {
                        allNumbers += i.ToString() + " ";
                        this.counterNumber++;
                    }
                }
            }

            return allNumbers;
        }

        private bool conditionCheking(int number)
        {
            int valueIndex0 = number / 1000;
            int valueIndex1 = number / 100 % 10;
            int vaelueIndex2 = number % 100 / 10;
            int valueIndex3 = number % 10;
            if (valueIndex0 + valueIndex3 == valueIndex1 + vaelueIndex2)
                return true;
            return false;
        }

        private void exitButton_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        Point lastPoint;
        private void resultPanel_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                this.Left += e.X - lastPoint.X;
                this.Top += e.Y - lastPoint.Y;
            }
        }

        private void resultPanel_MouseDown(object sender, MouseEventArgs e)
        {
            lastPoint = new Point(e.X, e.Y);
        }
    }
}
