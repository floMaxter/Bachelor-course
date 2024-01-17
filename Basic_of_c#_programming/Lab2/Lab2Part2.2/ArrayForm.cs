using System;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab2Part2._2
{
    public partial class ArrayForm : Form
    {
        private int valFraq;
        private int[] array;
        private long sumResult;
        private string strElementsResult;
        private string strPairBySignResult;

        public object Tack { get; private set; }

        public ArrayForm(int arrLength, 
                         bool isRandomFilling, 
                         int valueFrequency)
        {
            InitializeComponent();
            this.valFraq = valueFrequency;
            this.array = new int[arrLength];
            textBoxLength.Text = arrLength.ToString();
            textBoxFillingType.Text = isRandomFilling.Equals(true) ? "random" : "by hand";
            if (isRandomFilling.Equals(true) && valFraq.Equals(1))
            {
                labelSuggestionToFill.Visible = false;
            }
            initDataGridView(arrLength, 1);
        }

        private void initDataGridView(int columns, int rows)
        {
            dataGridView1.AllowUserToAddRows = false;
            dataGridView1.ColumnCount = columns + 1;
            dataGridView1.RowCount = rows;
            dataGridView1.Rows[0].Cells[0].Value = "Source Array";
            dataGridView1.Rows[0].Cells[0].ReadOnly = true;

            for (int i = 1; i <= columns; i++)
            {
                dataGridView1.Columns[i].Name = i.ToString();
            }

            for (int i = 0; i < array.Length; i++)
            {
                dataGridView1.Rows[0].Cells[i + 1].Value = "-";
            }
        }

        public void fillRandomArray(bool isFrequencyTimerTurnOn)
        {
            Random randomNumber = new Random();
            for(int i = 0; i < array.Length; i+= valFraq)
            {
                if(isFrequencyTimerTurnOn)
                {
                    Random randomTimeSleep = new Random();
                    int timeSleep = randomTimeSleep.Next(0, 4000);
                    Task.Delay(timeSleep);
                    MessageBox.Show("Element was generated " + timeSleep + "ms");
                }
                array[i] = randomNumber.Next();
                dataGridView1.Rows[0].Cells[i + 1].Value = array[i];
            }
        }

        private void fillByHandArray()
        {
            for (int i = 0; i < array.Length; i++)
            {
                string inputValue = dataGridView1.Rows[0].Cells[i + 1].Value.ToString();
                inputGridViewValidation(inputValue);
                array[i] = Convert.ToInt32(inputValue);
            }
        }

        private void inputGridViewValidation(string strValue)
        {
            if (strValue.All(Char.IsLetter))
                throw new Exception("Incorrect value in cells dataGridView!");
        }

        private long resultTimeOneThread()
        {
            Stopwatch stopwatch = new Stopwatch();
            stopwatch.Start();
            sumResult = doubleSumPositiveElementsResult();
            strElementsResult = indexElements();
            strPairBySignResult = pairBySign();
            stopwatch.Stop();
            return stopwatch.ElapsedMilliseconds;
        }

        private long resultTimeThreeThread()
        {
            Stopwatch stopwatch = new Stopwatch();
            stopwatch.Start();
            Thread firstTack = new Thread(() =>
            {
                doubleSumPositiveElementsResult();
            });
            
            Thread secondTack = new Thread(() =>
            {
                indexElements();
            });
            
            Thread thirdTack = new Thread(() =>
            {
                pairBySign();
            });

            firstTack.Start();
            secondTack.Start();
            thirdTack.Start();

            firstTack.Join();
            secondTack.Join();
            thirdTack.Join();

            stopwatch.Stop();

            return stopwatch.ElapsedMilliseconds;
        }

        //first tack
        private long doubleSumPositiveElementsResult()
        {
            long sum = 0;
            for(int i = 0; i < array.Length; i++)
            {
                if(array[i] > 0)
                {
                    sum += array[i];
                }
            }
            return sum;
        }

        //second tack
        private string indexElements()
        {
            StringBuilder sb = new StringBuilder();
            for(int i = 1; i < array.Length; i++)
            {
                if(array[i - 1] < array[i])
                {
                    sb.Append(i).Append(" ");
                }
            }
            return sb.ToString();
        }

        //third tack
        private string pairBySign()
        {
            StringBuilder sb = new StringBuilder();
            for(int i = 1; i < array.Length; i++)
            {
                int signFirst = Math.Sign(array[i - 1]);
                int signSecond = Math.Sign(array[i]);
                if(signFirst.Equals(signSecond)) {
                    sb.Append(array[i - 1]).Append(" and ").Append(array[i]).AppendLine();
                }
            }
            return sb.ToString();
        }

        
        private void selectEmptyCells()
        {
            for(int i = 1; i < dataGridView1.ColumnCount; i++)
            {
                if (dataGridView1.Rows[0].Cells[i].Value.Equals("-"))
                {
                    dataGridView1.Rows[0].Cells[i].Style.BackColor = Color.Red;
                } else
                {
                    dataGridView1.Rows[0].Cells[i].Style.BackColor = Color.White;
                }
            }
        }

        private void selectWrongCells()
        {
            for (int i = 1; i < dataGridView1.ColumnCount; i++)
            {
                string value = dataGridView1.Rows[0].Cells[i].Value.ToString();
                if (value.All(Char.IsLetter))
                {
                    dataGridView1.Rows[0].Cells[i].Style.BackColor = Color.Red;
                }
                else
                {
                    dataGridView1.Rows[0].Cells[i].Style.BackColor = Color.White;
                }
            }
        }

        private bool isArrayFull()
        { 
            for(int i = 1; i < dataGridView1.ColumnCount; i++)
            {
                if(dataGridView1.Rows[0].Cells[i].Value.Equals("-"))
                {
                    return false;
                }
            }
            return true;
        }

        private void buttonSend_Click(object sender, EventArgs e)
        {
            if (!isArrayFull())
            {
                MessageBox.Show("Fill the array!");
                selectEmptyCells();
            }
            else
            {
                try
                {
                    fillByHandArray();

                    long timeOneThread = resultTimeOneThread();
                    long timeThreeThread = resultTimeThreeThread();

                    ResultForm resultForm = new ResultForm(checkBoxTimer.Checked,
                                                           sumResult,
                                                           strElementsResult.ToString(),
                                                           strPairBySignResult.ToString(),
                                                           timeOneThread,
                                                           timeThreeThread);
                    this.Hide();
                    resultForm.Show();
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error! " + ex.Message);
                    selectWrongCells();
                }
            }
        }
    }
}
