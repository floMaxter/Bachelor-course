using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace All_Lab
{
    public partial class ParssingForm : Form
    {
        private Form mainForm;
        private string currentText;
        private MatchCollection matchResult;
        private string signature;
        private string[] signatureMyForm;
        private Color[] colorForSignature;
        private int currentColor = 0;
        private string myIP = "\\188.242.29.135";
        public ParssingForm(Form mainForm)
        {
            InitializeComponent();
            this.mainForm = mainForm;

            signatureMyForm = new string[]
            {
                "Lab1.cs",
                "Lab2.cs",
                "Lab3.cs",
                "Lab4.cs"
            };

            colorForSignature = new Color[]
            {
                Color.Red,
                Color.Blue,
                Color.Yellow,
                Color.Lime,
                Color.CadetBlue,
                Color.Gold,
                Color.Pink,
                Color.ForestGreen,
                Color.Indigo,
                Color.Cyan,
                Color.Orange,
                Color.LightSalmon
            };
        }

        private void openFileButton_Click(object sender, EventArgs e)
        {
            string fileContent = string.Empty;
            using (OpenFileDialog openFileDialog = new OpenFileDialog())
            {
                //openFileDialog.InitialDirectory = "c:\\";
                openFileDialog.InitialDirectory = "d:\\Studies\\TP\\Lab2\\";
                openFileDialog.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
                openFileDialog.FilterIndex = 2;
                openFileDialog.RestoreDirectory = true;

                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    using (StreamReader reader = new StreamReader(openFileDialog.FileName, Encoding.Default))
                    {
                        fileContent = reader.ReadToEnd();
                    }
                }
            }
            mainRichTextBox.Text = fileContent;
        }

        private void signatureSearchButton_Click(object sender, EventArgs e)
        {
            this.currentText = mainRichTextBox.Text;
            this.signature = comboBoxSignature.Text;

            MatchCollection matchResult = MatchLibrary.Class1.Find(currentText, signature);
            this.mainTextBox.Text = "All occurrences of the string '\"'" +
                                    signature + "'\"'" + "in the source text\r\n";
            if (matchResult.Count > 0)
            {
                foreach (Match match in matchResult)
                {
                    mainTextBox.Text += match.Index + " position" + "\t" + match.Value + "\r\n";
                }
            }
            else
            {
                mainTextBox.Text = "No matches found";
            }
        }

        private void inclusionButton_Click(object sender, EventArgs e)
        {
            mainRichTextBox.Select(0, mainRichTextBox.MaxLength);
            mainRichTextBox.SelectionColor = Color.Black;
            currentText = mainRichTextBox.Text;
            signature = comboBoxSignature.Text;

            matchResult = MatchLibrary.Class1.Find(currentText, signature);
            foreach(Match match in matchResult)
            {
                setSelectionStyle(match.Index, match.Length, FontStyle.Regular);
            }
            currentColor++;
        }

        private void buttonTimeRange_Click(object sender, EventArgs e)
        {
            if (textBoxFirstTime != null && textBoxSecondTime != null)
            {
                string firstTime = this.textBoxFirstTime.Text;
                string secondTime = this.textBoxSecondTime.Text;

                MatchCollection mathesFirstTime = MatchLibrary.Class1.Time(firstTime);
                MatchCollection mathesSecondTime = MatchLibrary.Class1.Time(secondTime);

                if (mathesFirstTime.Count < 1)
                {
                    MessageBox.Show("The first time range was entered incorrectly!");
                    MessageBox.Show("Enter data as format: hh.mm.ss");
                }
                if (mathesSecondTime.Count < 1)
                {
                    MessageBox.Show("The second time range was entered incorrectly!");
                    MessageBox.Show("Enter data as format: hh.mm.ss");
                }
                else
                {
                    currentText = mainRichTextBox.Text;   
                    string[] firstSplitTime = firstTime.Split(new char[] { ':' });
                    string[] secondSplitTime = secondTime.Split(new char[] { ':' });
                    int firstTimeInSeconds = convertTimeToSeconds(firstSplitTime);
                    int secondTimeInSeconds = convertTimeToSeconds(secondSplitTime);

                    MatchCollection matchResultForTime = MatchLibrary.Class1.Time(this.currentText);
                    ArrayList suitableTemporaryIndexes = new ArrayList();
                    if (matchResultForTime != null)
                    {
                        //Finding and allocating the right time
                        foreach (Match match in matchResultForTime)
                        {
                            string[] currentSplitTime = match.Value.Split(new char[] { ':' });
                            int currentTimeInSeconds = convertTimeToSeconds(currentSplitTime);
                            if (currentTimeInSeconds >= firstTimeInSeconds && currentTimeInSeconds <= secondTimeInSeconds)
                            {
                                setSelectionStyle(match.Index, match.Length, FontStyle.Regular);
                                suitableTemporaryIndexes.Add(match.Index);
                            }
                        }

                        //Finding and allocating the right signatureForm "Lab*.cs"
                        int shiftByMatchIndex = 0;
                        for (int i = 0; i < signatureMyForm.Length; i++)
                        {
                            MatchCollection matchResultForForm = MatchLibrary.Class1.Find(currentText, signatureMyForm[i]);
                            foreach (Match match in matchResultForForm)
                            {
                                for(int j = 0; j < suitableTemporaryIndexes.Count; j++)
                                {
                                    int startIndexRange = (int)suitableTemporaryIndexes[j] - 20;
                                    int endIndexRange = (int)suitableTemporaryIndexes[j];
                                    if (match.Index + shiftByMatchIndex >= startIndexRange && match.Index + shiftByMatchIndex < endIndexRange)
                                    {
                                        this.mainRichTextBox.Select(match.Index + match.Length + shiftByMatchIndex, 0);
                                        this.mainRichTextBox.SelectedText = myIP;
                                        setSelectionStyle(match.Index + shiftByMatchIndex, match.Length + myIP.Length, FontStyle.Regular);
                                        addShiftByInex(myIP.Length, suitableTemporaryIndexes);
                                        shiftByMatchIndex += myIP.Length;
                                        currentColor++;
                                    }
                                }
                            }
                        }

                    }
                    else
                    {
                        mainTextBox.Text = "No matches found";
                    }
                    currentColor++;
                }
            }
        }

        private int convertTimeToSeconds(string[] time)
        {
            int hours = Convert.ToInt32(time[0]);
            int minutes = Convert.ToInt32(time[1]);
            int seconds = Convert.ToInt32(time[2]);
            return hours * 60 * 60 + minutes * 60 + seconds;
        }

        private void setSelectionStyle(int startIndex, int length, FontStyle style)
        {
            mainRichTextBox.Select(startIndex, length);
            mainRichTextBox.SelectionFont = new Font(mainRichTextBox.SelectionFont, mainRichTextBox.SelectionFont.Style | style);
            mainRichTextBox.SelectionColor = colorForSignature[currentColor % 12];
        }

        private void addShiftByInex(int lengthShift, ArrayList list)
        {
            for(int i = 0; i < list.Count; i++)
            {
                list[i] = ((int)list[i]) + lengthShift;
            }
        }


        private void addButton_Click(object sender, EventArgs e)
        {
            this.comboBoxSignature.Items.Add(comboBoxSignature.Text);
        }

        private MatchCollection Find(string str, string signature)
        {
            Regex regex = new Regex(signature, RegexOptions.IgnoreCase);
            if (str != null)
            {
                MatchCollection matches = regex.Matches(str);
                return matches;
            }
            else
            {
                return null;
            }
        }

        public static MatchCollection Time(string str)
        {
            string timeSignature = "([01]?[0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9]";
            Regex regex = new Regex(timeSignature);
            if (str != null)
            {
                MatchCollection matches = regex.Matches(str);
                return matches;
            }
            else
                return null;
        }

        private void formSearchbutton_Click(object sender, EventArgs e)
        {
            int count = 0;
            bool check = false;
            mainRichTextBox.Select(0, mainRichTextBox.MaxLength);
            mainRichTextBox.SelectionColor = Color.Black;
            mainTextBox.Text = string.Empty;
            this.currentText = mainRichTextBox.Text;
            for(int i = 0; i < signatureMyForm.Length; i++)
            {
                matchResult = MatchLibrary.Class1.Find(currentText, signatureMyForm[i]);
                if(matchResult.Count > 0)
                {
                    foreach(Match match in matchResult)
                    {
                        setSelectionStyle(match.Index, match.Length, FontStyle.Regular);
                        count++;
                    }
                    check = true;
                    mainTextBox.Text += "Exception occurred in form '\"'" + signatureMyForm[i] + "'\"' " + count + " times\r\n";
                    count = 0;
                }
                if(!check)
                {
                    mainTextBox.Text = "Exception not fount";
                }
            }
            currentColor++;
        }
    }
}
