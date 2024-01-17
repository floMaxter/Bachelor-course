using System.Windows.Forms;

namespace Lab2Part2._2
{
    public partial class ResultForm : Form
    {
        public ResultForm(bool enableTimerChecked, 
                          long sum, 
                          string index, 
                          string pair, 
                          long timeOneThread, 
                          long timeThreeThread)
        {
            InitializeComponent();
            textBoxPair.Multiline = true;
            textBoxPair.ScrollBars = ScrollBars.Both;
            textBoxIndex.ScrollBars = ScrollBars.Both;


            textBoxSum.Text = sum.ToString();
            textBoxIndex.Text = index;
            textBoxPair.Text = pair;
            textBoxOneThread.Text = timeOneThread.ToString();
            textBoxSomeThread.Text = timeThreeThread.ToString();
            
            if (!enableTimerChecked)
            {
                labelOneThread.Visible = false;
                labelSomeThread.Visible = false;
                textBoxOneThread.Visible = false;
                textBoxSomeThread.Visible = false;
            }
        }
    }
}
