using System;
using System.Drawing;
using System.Linq;
using System.Windows.Forms;

namespace Lab1Part2._2WindowsForms
{
    public partial class Exercice1 : Form
    {
        public Exercice1()
        {
            InitializeComponent();
        }

        private void exitButton_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void SendButton_Click(object sender, EventArgs e)
        {
            if(NumberArea.TextLength.Equals(0))
            {
                MessageBox.Show("Text length == 0");
                Application.Exit();
            }
            if(AreaNumberA.TextLength.Equals(0))
            {
                MessageBox.Show("Text length == 0");
                Application.Exit();
            }
            //Изменить проверку
            if(AreaNumberA.TextLength > 1)
            {
                MessageBox.Show("Invalid length number a");
                Application.Exit();
            }

            String numberStr = NumberArea.Text;
            String valueAStr = AreaNumberA.Text;
            if (!(isCorrectData(numberStr) && isCorrectData(valueAStr)))
            {
                MessageBox.Show("Invalid text. Try again.");    
                NumberArea.Clear();
                AreaNumberA.Clear();
            } else
            {
                int number = Int32.Parse(numberStr);
                int valueA = Int32.Parse(valueAStr);

                this.Hide();
                Result1 res = new Result1(number, valueA);
                res.Show();
            }
        }

        
        private bool isCorrectData(String message)
        {
            if (message.Equals(String.Empty))
            {
                return false;
            }
            if (message[0].Equals('0'))
            {
                return false;
            }

            return message.All(Char.IsDigit);
        }

        Point lastPoint;
        private void MainPanel_MouseMove_1(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                this.Left += e.X - lastPoint.X;
                this.Top += e.Y - lastPoint.Y;
            }
        }
        private void MainPanel_MouseDown(object sender, MouseEventArgs e)
        {
            lastPoint = new Point(e.X, e.Y);
        }

        private void EnterNumberLabel_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                this.Left += e.X - lastPoint.X;
                this.Top += e.Y - lastPoint.Y;
            }
        }
            
        private void EnterNumberLabel_MouseDown(object sender, MouseEventArgs e)
        {
            lastPoint = new Point(e.X, e.Y);
        }

        private void NumberArea_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                this.Left += e.X - lastPoint.X;
                this.Top += e.Y - lastPoint.Y;
            }
        }

        private void NumberArea_MouseDown(object sender, MouseEventArgs e)
        {
            lastPoint = new Point(e.X, e.Y);
        }

        private void EnterALabel_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                this.Left += e.X - lastPoint.X;
                this.Top += e.Y - lastPoint.Y;
            }
        }

        private void EnterALabel_MouseDown(object sender, MouseEventArgs e)
        {
            lastPoint = new Point(e.X, e.Y);
        }

        private void AreaNumberA_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                this.Left += e.X - lastPoint.X;
                this.Top += e.Y - lastPoint.Y;
            }
        }

        private void AreaNumberA_MouseDown(object sender, MouseEventArgs e)
        {
            lastPoint = new Point(e.X, e.Y);
        }
    }
}
