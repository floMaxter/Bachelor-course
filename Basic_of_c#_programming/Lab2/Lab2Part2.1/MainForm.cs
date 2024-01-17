using System;
using System.Linq;
using System.Windows.Forms;

namespace Lab2Part2._1
{
    public partial class MainForm : Form
    {
        private string name = string.Empty;
        private string surname = string.Empty;
        private int age = 0;
        private LogForm logForm = new LogForm();
        public MainForm()
        {
            InitializeComponent();
            this.logForm.Show();
        }

        private void buttonSend_Click(object sender, EventArgs e)
        {
            try
            {
                if (!isCorrectData(textBoxName.Text, "String"))
                    throw new Exception("Incorrectly entered name.");
                else if (!isCorrectData(textBoxSurname.Text, "String"))
                    throw new Exception("Incorrectly entered surname.");
                else if (!isCorrectData(textBoxAge.Text, "Integer"))
                    throw new Exception("Incorrectly entered age.");
                else
                {
                    name = textBoxName.Text;
                    surname = textBoxSurname.Text;
                    age = Int32.Parse(textBoxAge.Text);
                    MessageBox.Show(name + "\n" + surname + "\n" + age);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error");
                string pathToFile = @"D:\Studies\TP\Lab2\Log2.txt";
                Log myLog = new Log("Invalid data. ", ex, pathToFile);
                logForm.readLog(pathToFile);
            }
        }

        private bool isCorrectData(string msg, string typeData)
        {
            if (msg.Length == 0)
                throw new Exception("Emtry value");
            if (typeData.Equals("String"))
                return msg.All(Char.IsLetter);
            else if (typeData.Equals("Integer"))
                return msg.All(Char.IsDigit);
            return false;
        }
    }
}
