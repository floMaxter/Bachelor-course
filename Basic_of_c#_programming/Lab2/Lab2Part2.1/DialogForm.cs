using System;
using System.IO;
using System.Windows.Forms;

namespace Lab2Part2._1
{
    public partial class DialogForm : Form
    {
        private TextBox textBox;
        public DialogForm(TextBox textBox)
        {
            this.textBox = textBox;
            InitializeComponent();
        }

        private void buttonYes_Click(object sender, EventArgs e)
        {
            string logContent = textBox.Text;
            using (SaveFileDialog saveFileDialog = new SaveFileDialog())
            {
                saveFileDialog.InitialDirectory = "c:\\";
                saveFileDialog.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
                saveFileDialog.FilterIndex = 2;
                saveFileDialog.RestoreDirectory = true;

                if (saveFileDialog.ShowDialog() == DialogResult.Cancel)
                    return;
                if (saveFileDialog.ShowDialog() == DialogResult.OK)
                {
                    if (logContent.Length == 0)
                    {
                        MessageBox.Show("Emty log!");
                    }
                    else
                    {
                        using (StreamWriter writer = new StreamWriter(saveFileDialog.FileName))
                        {
                            writer.WriteLine(logContent);
                        }
                    }
                }
            }
        }

        private void buttonNo_Click(object sender, EventArgs e)
        {
            textBox.Clear();
            this.Hide();
        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            this.Hide();
        }
    }
}
