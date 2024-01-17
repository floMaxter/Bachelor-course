using System;
using System.Drawing;
using System.IO;
using System.Security.Cryptography;
using System.Text;
using System.Windows.Forms;

namespace Lab1.Part2._1
{
    public partial class AdditionForm : Form
    {
        private String name = String.Empty;
        private String surname = String.Empty;
        public AdditionForm(byte[] encryptedName, byte[] encryptedSurname, Aes myAes)
        {
            try
            {
                this.name = decryptStringFromBytes(encryptedName, myAes.Key, myAes.IV);
                this.surname = decryptStringFromBytes(encryptedSurname, myAes.Key, myAes.IV);
                showEncryptedMessage(encryptedName, encryptedSurname);
                InitializeComponent();
                this.resultField.Text = bitwiseAdditionOfString();
            } catch(ArgumentNullException ex)
            {
                MessageBox.Show(ex.ParamName);
                Application.Exit();
            }
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
        private void autorizationPanel_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                this.Left += e.X - lastPoint.X;
                this.Top += e.Y - lastPoint.Y;
            }
        }

        private void autorizationPanel_MouseDown(object sender, MouseEventArgs e)
        {
            lastPoint = new Point(e.X, e.Y);
        }

        private void MainPanel_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                this.Left += e.X - lastPoint.X;
                this.Top += e.Y - lastPoint.Y;
            }
        }

        private void MainPanel_MouseMove(object sender, MouseEventArgs e)
        {
            lastPoint = new Point(e.X, e.Y);
        }

        static String decryptStringFromBytes(byte[] cipherMessage, byte[] key, byte[] initVector)
        {
            if (cipherMessage == null || cipherMessage.Length <= 0)
                throw new ArgumentNullException("cipherMessage");
            if (key == null || key.Length <= 0)
                throw new ArgumentNullException("key");
            if (initVector == null || initVector.Length <= 0)
                throw new ArgumentNullException("IV");

            string plaintext = null;
            using (Aes aesAlg = Aes.Create())
            {
                aesAlg.Key = key;
                aesAlg.IV = initVector;
                ICryptoTransform decryptor = aesAlg.CreateDecryptor(aesAlg.Key, aesAlg.IV);
                using (MemoryStream msDecrypt = new MemoryStream(cipherMessage))
                {
                    using (CryptoStream csDecrypt = new CryptoStream(msDecrypt, decryptor, CryptoStreamMode.Read))
                    {
                        using (StreamReader srDecrypt = new StreamReader(csDecrypt))
                        {
                            plaintext = srDecrypt.ReadToEnd();
                        }
                    }
                }
            }
            return plaintext;
        }

        private String bitwiseAdditionOfString() 
        {
            int lenghtMessage = Math.Max(name.Length, surname.Length);
            char[] nameSymbolArr = new char[name.Length];
            char[] surnameSymbolArr = new char[surname.Length];
            char[] resultSymbolArr = new char[lenghtMessage];
            for (int i = 0; i < name.Length; i++)
            {
                nameSymbolArr[i] = name[i];
            }
            for (int i = 0; i < surname.Length; i++)
            {
                surnameSymbolArr[i] = surname[i];
            }
            for (int i = 0; i < lenghtMessage; i++)
            {
                if (i >= name.Length)
                {
                    resultSymbolArr[i] = (char)surnameSymbolArr[i];
                }
                else if (i >= surname.Length)
                {
                    resultSymbolArr[i] = (char)nameSymbolArr[i];
                } else
                {
                    resultSymbolArr[i] = (char)(nameSymbolArr[i] | surnameSymbolArr[i]);
                }
            }

            return midwayValue(nameSymbolArr, surnameSymbolArr, resultSymbolArr);
        }

        private String midwayValue(char[] name, char[] surname, char[] resultSymbolArr)
        {
            StringBuilder resultSb = new StringBuilder();
            resultSb.Append(messageUTF16(name)).Append("\n").Append(messageUnicode(name)).Append("\n");
            resultSb.Append(messageUTF16(surname)).Append("\n").Append(messageUnicode(surname)).Append("\n");
            resultSb.Append(messageUTF16(resultSymbolArr)).Append("\n").Append(messageUnicode(resultSymbolArr)).Append("\n");
            return resultSb.ToString();
        }

        private void showEncryptedMessage(byte[] encrName, byte[] encrSurname)
        {
            StringBuilder sb = new StringBuilder();
            sb.Append("Name: ");
            foreach (var ch in encrName)
            {
                sb.Append(ch);
            }
            sb.Append("\nSurname: ");
            foreach (var ch in encrSurname)
            {
                sb.Append(ch);
            }
            sb.Append("\n");
            MessageBox.Show(sb.ToString());
        }
        private String messageUTF16(char[] message)
        {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < message.Length; i++)
            {
                sb.Append((char)message[i]).Append(" ");
            }
            return sb.ToString();
        }

        private String messageUnicode(char[] message)
        {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < message.Length; i++)
            {
                sb.Append((int)message[i]).Append(" ");
            }
            return sb.ToString();
        }
    }
}
