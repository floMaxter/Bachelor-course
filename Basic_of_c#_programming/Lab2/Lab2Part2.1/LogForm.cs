    using System;
using System.IO;
using System.Windows.Forms;

namespace Lab2Part2._1
{
    public partial class LogForm : Form
    {
        public LogForm()
        {
            InitializeComponent();
            Timer timer = new Timer();
            timer.Interval = 1000;
            timer.Enabled = true;
            timer.Tick += new EventHandler(timerTick);
        }

        public void timerTick(object sender, EventArgs e)
        {
            toolStripStatusDataLabel.Text = DateTime.Now.ToShortDateString() + ", " + DateTime.Now.ToLongTimeString();
        }

        public void showLogInfo(string message)
        {
            textBox.Text = message;
        }

        public void readLog(string path)
        {
            using (StreamReader streamReader = new StreamReader(path))
            {
                textBox.Text = streamReader.ReadToEnd();
            }
        }

        private void toolStripOpenLabel_Click(object sender, EventArgs e)
        {
            string fileContent = string.Empty;
            using (OpenFileDialog openFileDialog = new OpenFileDialog())
            {
                openFileDialog.InitialDirectory = "c:\\";
                openFileDialog.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
                openFileDialog.FilterIndex = 2;
                openFileDialog.RestoreDirectory = true;
            
                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    using (StreamReader reader = new StreamReader(openFileDialog.FileName))
                    {
                        fileContent = reader.ReadToEnd();
                    }
                }
            }
            textBox.Text = fileContent;
        }

        private void toolStripSaveLabel_Click(object sender, EventArgs e)
        {
            string logContent = textBox.Text;
            using (SaveFileDialog saveFileDialog = new SaveFileDialog())
            {
                saveFileDialog.InitialDirectory = "c:\\";
                saveFileDialog.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
                saveFileDialog.FilterIndex = 1;
                saveFileDialog.RestoreDirectory = true;

                if(saveFileDialog.ShowDialog() == DialogResult.OK)
                {
                    using (StreamWriter writer = new StreamWriter(saveFileDialog.FileName))
                    {
                        writer.WriteLine(logContent);
                    }
                }
            }
        }

        private void toolStripCreateLabel_Click(object sender, EventArgs e)
        {
            DialogForm dialog = new DialogForm(this.textBox);
            dialog.Show();
        }

        private void lab2ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            readLog(@"D:\Studies\TP\Lab2\Log2.txt");
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
