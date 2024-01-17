using System;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Windows.Forms;

namespace Lab1.Part2._1
{
    public partial class LoginForm : Form
    {
        public LoginForm()
        {
            InitializeComponent();
            this.nameField.AutoSize = false;
            this.surnameField.AutoSize = false;
            this.nameField.Size = new Size(this.nameField.Width, 50);
            this.surnameField.Size = new Size(this.surnameField.Width, 50);
        }

        private void closeButton_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void closeButton_MouseEnter(object sender, EventArgs e)
        {
            closeButton.ForeColor = Color.Red;
        }

        private void closeButton_MouseLeave(object sender, EventArgs e)
        {
            closeButton.ForeColor = Color.White;
        }

        Point lastPoint;
        private void MainPanel_MouseMove(object sender, MouseEventArgs e)
        {
            if(e.Button == MouseButtons.Left)
            {
                this.Left += e.X - lastPoint.X;
                this.Top += e.Y - lastPoint.Y;
            }
        }

        private void MainPanel_MouseDown(object sender, MouseEventArgs e)
        {
            lastPoint = new Point(e.X, e.Y);
        }

        private void autorizationPanel_MouseMove(object sender, MouseEventArgs e)
        {
            if(e.Button == MouseButtons.Left)
            {
                this.Left += e.X - lastPoint.X;
                this.Top += e.Y - lastPoint.Y;
            }
        }

        private void autorizationPanel_MouseDown(object sender, MouseEventArgs e)
        {
            lastPoint = new Point(e.X, e.Y);
        }

        private void userPictureBox_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                this.Left += e.X - lastPoint.X;
                this.Top += e.Y - lastPoint.Y;
            }
        }

        private void userPictureBox_MouseDown(object sender, MouseEventArgs e)
        {
            lastPoint = new Point(e.X, e.Y);
        }

        private void namePanel_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                this.Left += e.X - lastPoint.X;
                this.Top += e.Y - lastPoint.Y;
            }
        }

        private void namePanel_MouseDown(object sender, MouseEventArgs e)
        {
            lastPoint = new Point(e.X, e.Y);
        }

        private void surnamePanel_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                this.Left += e.X - lastPoint.X;
                this.Top += e.Y - lastPoint.Y;
            }
        }

        private void surnamePanel_MouseDown(object sender, MouseEventArgs e)
        {
            lastPoint = new Point(e.X, e.Y);
        }

        private void sendButton_Click(object sender, EventArgs e)
        {
            String name = nameField.Text;
            String surname = surnameField.Text;
            if (!(isCorrectData(name) && isCorrectData(surname)))
            {
                MessageBox.Show("Incorrect name or surname");
                Application.Exit();
            } else
            {
                this.Hide();
                using (Aes myAes = Aes.Create())
                {
                    byte[] encryptedName = encryptStringToBytes(name, myAes.Key, myAes.IV);
                    byte[] encryptedSurname = encryptStringToBytes(surname, myAes.Key, myAes.IV);
                    AdditionForm additionForm = new AdditionForm(encryptedName, encryptedSurname, myAes);
                    additionForm.Show();
                }
            }
        }

        static byte[] encryptStringToBytes(String message, byte[] key, byte[] initVector)
        {
            if (message == null || message.Length <= 0)
                throw new ArgumentNullException("message");
            if (key == null || key.Length <= 0)
                throw new ArgumentNullException("key");
            if (initVector == null || initVector.Length <= 0)
                throw new ArgumentNullException("initVector");

            byte[] encrypted;
            using (Aes aesAlg = Aes.Create())
            {
                aesAlg.Key = key;
                aesAlg.IV = initVector;
                ICryptoTransform encryptor = aesAlg.CreateEncryptor(aesAlg.Key, aesAlg.IV);
                using (MemoryStream msEncrypt = new MemoryStream())
                {
                    using (CryptoStream csEncrypt = new CryptoStream(msEncrypt, encryptor, CryptoStreamMode.Write))
                    {
                        using (StreamWriter swEncrypt = new StreamWriter(csEncrypt))
                        {
                            swEncrypt.Write(message);
                        }
                        encrypted = msEncrypt.ToArray();
                    }
                }
            }
            return encrypted;
        }

        private bool isCorrectData(String message)
        {
            if(message.Equals(String.Empty))
            {
                return false;
            }
            return message.All(Char.IsLetter);
        }
    }
}
