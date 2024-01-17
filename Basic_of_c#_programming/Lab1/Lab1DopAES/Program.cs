using System;
using System.IO;
using System.Security.Cryptography;
using System.Text;

namespace Lab1DopAES
{
    class Program
    {
        static void Main(string[] args)
        {
            String originalMessage = String.Empty;
            Console.WriteLine("Enter the message to be encrypted: ");
            originalMessage = Console.ReadLine();
            
            using (Aes myAes = Aes.Create())
            {
                byte[] encrypted = encryptStringToBytes(originalMessage, myAes.Key, myAes.IV);
                String roundtrip = decryptStringFromBytes(encrypted, myAes.Key, myAes.IV);
                StringBuilder sb = new StringBuilder();
                foreach(var ch in encrypted)
                {
                    sb.Append(ch);
                }
                Console.WriteLine("Original: " + originalMessage);
                Console.WriteLine("After encrypted: " + sb.ToString());
                Console.WriteLine("Round Trip: " + roundtrip);
            }
        }

        static byte[] encryptStringToBytes(String message, byte[] key, byte[] initVector)
        {
            if(message == null || message.Length <= 0)
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

        static string decryptStringFromBytes(byte[] cipherMessage, byte[] key, byte[] initVector)
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
    }
}
