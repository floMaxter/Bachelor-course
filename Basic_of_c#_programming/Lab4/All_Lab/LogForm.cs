using All_Lab;
using System;
using System.IO;
using System.Windows.Forms;

namespace All_Lab
{
    public partial class LogForm : Form
    {
        private string pathToLogContentLab1 = @"D:\Studies\TP\Lab1\Log1.txt";
        private string pathToLogContentLab2 = @"D:\Studies\TP\Lab2\Log2.txt";
        private string pathToLogContentLab3 = @"D:\Studies\TP\Lab3\Log3.txt";
        private string pathToLogContentLab4 = @"D:\Studies\TP\Lab4\All_Lab\Log4.txt";
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

        private void readLog(string path)
        {
            textBox.Text = showFileContent(path);
        }

        private void readLogFromAllLabs(string path)
        {
            String logContentLab1 = showFileContent(pathToLogContentLab1);
            String logContentLab2 = showFileContent(pathToLogContentLab2);
            String logContentLab3 = showFileContent(pathToLogContentLab3);
            String logContentLab4 = showFileContent(path);

            using (StreamWriter writer = File.AppendText(path))
            {
                //writer.WriteLine(logContentLab1);
                writer.WriteLine(logContentLab2);
                //writer.WriteLine(logContentLab3);
                //writer.WriteLine(logContentLab4);
            }

            textBox.Text = showFileContent(path);
        }

        private String showFileContent(string path)
        {
            string content = String.Empty;
            using (StreamReader streamReader = new StreamReader(path))
            {
                content = streamReader.ReadToEnd();
            }
            return content;
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

        private void lab1ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            readLog(pathToLogContentLab1);
        }

        private void lab2ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            readLog(pathToLogContentLab2);
        }

        private void lab3ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            readLog(pathToLogContentLab3);
        }

        private void lab4ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            readLogFromAllLabs(pathToLogContentLab4);
            ParssingForm parsingForm = new ParssingForm(this);
            parsingForm.Show();
        }


        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
