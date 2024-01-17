using System;
using System.Linq;
using System.Windows.Forms;

namespace QueueOnTwoStack
{
    public partial class MainForm : Form
    {
        private QueueOnTwoStack queue;
        private int sizeQueue;
        private int lengthQueue;
        public MainForm()
        {
            InitializeComponent();
            queue = new QueueOnTwoStack();
            sizeQueue = Convert.ToInt32(numericUpDownsizeQueue.Value);
            lengthQueue = 0;
            initDataGridView(sizeQueue, 1);
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

            for (int i = 0; i < sizeQueue; i++)
            {
                dataGridView1.Rows[0].Cells[i + 1].Value = "-";
            }
        }

        private void shiftValueDataGridViewRight()
        {
            int[] arr = new int[lengthQueue];
            for(int i = 0; i < lengthQueue - 1; i++)
            {
                arr[i] = Convert.ToInt32(dataGridView1.Rows[0].Cells[i + 1].Value);
            }
            
            for(int i = 0; i < lengthQueue - 1; i++)
            {
                dataGridView1.Rows[0].Cells[i + 2].Value = arr[i];
            } 

        }

        private void insertValueInDataGridView(int inputValue)
        {
            dataGridView1.Rows[0].Cells[1].Value = inputValue;
        }

        private void insertValue(int inputValue)
        {
            queue.enQueue(inputValue);
            lengthQueue++;
            shiftValueDataGridViewRight();
            insertValueInDataGridView(Convert.ToInt32(inputValue));
        }

        private void deleteValueInDataGridView()
        {
            dataGridView1.Rows[0].Cells[lengthQueue].Value = "-";
        }

        private bool isCorrectData(string value)
        {
            if (value.Equals(String.Empty))
                return false;
            return value.All(Char.IsDigit);
        }

        private void buttonEqueue_Click(object sender, EventArgs e)
        {
            if (!isCorrectData(textBoxEnqueue.Text))
            {
                MessageBox.Show("Incorrect value. Try again!");
                textBoxEnqueue.Text = String.Empty;
            }
            else if (lengthQueue == sizeQueue)
            {
                int output = queue.deQueue();
                textBoxDequeue.Text = output.ToString();
                deleteValueInDataGridView();
                lengthQueue--;
                insertValue(Convert.ToInt32(textBoxEnqueue.Text));
            }
            else
            {
                insertValue(Convert.ToInt32(textBoxEnqueue.Text));
            }
        }
        private void buttonDequeue_Click(object sender, EventArgs e)
        {
            if (lengthQueue == 0)
            {
                MessageBox.Show("Queue is empty!");
            }
            else
            {
                int outputValue = queue.deQueue();
                textBoxDequeue.Text = outputValue.ToString();
                deleteValueInDataGridView();
                lengthQueue--;
            }
        }

        private void buttonResize_Click(object sender, EventArgs e)
        {
            int[] arr = new int[lengthQueue];
            for (int i = 0; i < lengthQueue; i++)
            {
                arr[i] = queue.deQueue();
            }

            sizeQueue = Convert.ToInt32(numericUpDownsizeQueue.Value);
            lengthQueue = 0;
            initDataGridView(sizeQueue, 1);
            
            if(sizeQueue > arr.Length)
            {
                for(int i = 0; i < arr.Length; i++)
                {
                    insertValue(arr[i]);
                }
            } else
            {
                for (int i = arr.Length - sizeQueue; i <= sizeQueue; i++)
                {
                    insertValue(arr[i]);
                }
            }
        }
    }
}
