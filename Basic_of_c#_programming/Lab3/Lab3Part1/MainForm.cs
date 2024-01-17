using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab3Part1
{
    public partial class MainForm : Form
    {
        private bool isMouse = false;
        private Point px, py;
        private string modeLine;
        private int x, y, sX, sY, cX, cY;
        
        private Bitmap pic;
        private Graphics graphics;
        private Pen pen;
        private Pen erase;
        private Color newColor;
        
        public MainForm()
        {
            InitializeComponent();
            pen = new Pen(Color.Black, 1);
            erase = new Pen(Color.White, 1);
            setSize();
            pictureBoxMain.Image = pic;
        }

        //Creating line
        private class ArrayPoints
        {
            private int index = 0;
            private Point[] points;
            public ArrayPoints(int size)
            {
                if (size <= 0)
                    size = 2;
                points = new Point[size];
            }

            public void setPoint(int x, int y)
            {
                if (index >= points.Length)
                {
                    index = 0;
                }
                points[index] = new Point(x, y);
                index++;
            }

            public void resetPoints()
            {
                index = 0;
            }

            public int getCountPoints()
            {
                return index;
            }

            public Point[] getPoints()
            {
                return points;
            }
        }

        private void setSize()
        {
            Rectangle rectangle = Screen.PrimaryScreen.Bounds;
            pic = new Bitmap(rectangle.Width, rectangle.Height);
            graphics = Graphics.FromImage(pic);
            graphics.Clear(Color.White);
            pen.StartCap = System.Drawing.Drawing2D.LineCap.Round;
            pen.EndCap = System.Drawing.Drawing2D.LineCap.Round;
        }

        private void pictureBoxMain_MouseMove(object sender, MouseEventArgs e)
        {
            if (isMouse)
            {
                if (modeLine == "line")
                {
                    px = e.Location;
                    graphics.DrawLine(pen, px, py);
                    py = px;
                }
                if(modeLine == "erase")
                {
                    px = e.Location;
                    graphics.DrawLine(erase, px, py);
                    py = px;
                }
             }
            pictureBoxMain.Refresh();

            x = e.X;
            y = e.Y;
            sX = e.X - cX;
            sY = e.Y - cY;
        }

        private void pictureBoxMain_MouseUp(object sender, MouseEventArgs e)
        {
            isMouse = false;

            sX = x - cX;
            sY = y - cY;

            if(modeLine == "ellipse")
            {
                graphics.DrawEllipse(pen, cX, cY, sX, sY);
            }
            if(modeLine == "rectangle")
            {
                graphics.DrawRectangle(pen, cX, cY, sX, sY);
            }
            if(modeLine == "ruler")
            {
                graphics.DrawLine(pen, cX, cY, x, y);
            }
        }

        private void pictureBoxMain_MouseDown(object sender, MouseEventArgs e)
        {
            isMouse = true;
            py = e.Location;

            cX = e.X;
            cY = e.Y;
        }

        //Color selection
        private void buttonWhite_Click(object sender, EventArgs e)
        {
            pen.Color = ((Button)sender).BackColor;
            pen.Width = trackBar1.Value;
            erase.Width = trackBar1.Value;
            newColor = ((Button)sender).BackColor;
        }

        private void buttonDefaultColor_Click(object sender, EventArgs e)
        {
            if(colorDialogForPen.ShowDialog() == DialogResult.OK)
            {
                pen.Color = colorDialogForPen.Color;
                pen.Width = trackBar1.Value;
                erase.Width = trackBar1.Value;
                ((Button)sender).BackColor = colorDialogForPen.Color;
                newColor = ((Button)sender).BackColor;
            }
        }

        private void buttonPouring_Click(object sender, EventArgs e)
        {
            if (colorDialogForBackground.ShowDialog() == DialogResult.OK)
            {
                modeLine = "fill";
                newColor = colorDialogForBackground.Color;
            }
        }


        //File Settings
        private void createToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //TODO: ask about saving file
            graphics.Clear(pictureBoxMain.BackColor);
            pictureBoxMain.Image = pic;
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            using (SaveFileDialog saveFileDialog = new SaveFileDialog())
            {
                saveFileDialog.InitialDirectory = "c:\\";
                saveFileDialog.Filter = "JPG(*.JPG)|*.jpg";
                saveFileDialog.FilterIndex = 1;
                saveFileDialog.RestoreDirectory = true;

                if (saveFileDialog.ShowDialog() == DialogResult.OK)
                {
                    if(pictureBoxMain.Image == null)
                    {
                        pictureBoxMain.Image.Save(saveFileDialog.FileName);
                    }
                }
            }
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string fileContent = string.Empty;
            using (OpenFileDialog openFileDialog = new OpenFileDialog())
            {
                openFileDialog.InitialDirectory = "c:\\";
                openFileDialog.Filter = "JPG(*.JPG)|*.jpg";
                openFileDialog.FilterIndex = 2;
                openFileDialog.RestoreDirectory = true;

                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    this.pictureBoxMain.Image = Image.FromFile(openFileDialog.FileName);
                    pic = new Bitmap(Image.FromFile(openFileDialog.FileName));
                    graphics = Graphics.FromImage(pic);
                }
            }
        }

        private void exiteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //Проверка на сохранение. Вызов диалогового окна
            Application.Exit();
        }

        private void trackBar1_ValueChanged(object sender, EventArgs e)
        {
            pen.Width = trackBar1.Value;
            erase.Width = trackBar1.Value;
        }

        //Type Figure
        private void buttonPen_Click(object sender, EventArgs e)
        {
            modeLine = "line";
            radioButtonRuler.Checked = false;
            radioButtonEllipse.Checked = false;
            radioButtonRectangle.Checked = false;
        }

        private void buttonErase_Click(object sender, EventArgs e)
        {
            modeLine = "erase";
        }

        private void radioButtonRuler_CheckedChanged_1(object sender, EventArgs e)
        {
            modeLine = "ruler";
        }

        private void radioButtonRectangle_CheckedChanged(object sender, EventArgs e)
        {
            modeLine = "rectangle";
        }

        private void radioButtonEllipse_CheckedChanged(object sender, EventArgs e)
        {
            modeLine = "ellipse";
        }
        private void pictureBoxMain_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            if(isMouse)
            {
                if (modeLine == "ellipse")
                {
                    g.DrawEllipse(pen, cX, cY, sX, sY);
                }
                if (modeLine == "rectangle")
                {
                    g.DrawRectangle(pen, cX, cY, sX, sY);
                }
                if (modeLine == "ruler")
                {
                    g.DrawLine(pen, cX, cY, x, y);
                }
            }
        }

        private void pictureBoxMain_MouseClick(object sender, MouseEventArgs e)
        {
            if(modeLine == "fill")
            {
                Point p = setPoint(pictureBoxMain, e.Location);
                fillFigure(pic, p.X, p.Y, newColor);
            }
        }

        static Point setPoint(PictureBox pb, Point pt)
        {
            float pX = 1f * pb.Width / pb.Width;
            float pY = 1f * pb.Height / pb.Height;
            return new Point((int)(pt.X * pX), (int)(pt.Y * pY));
        }

        private void validate(Bitmap bm, Stack<Point> sp, int x, int y, Color oldColor, Color newColor)
        {
            Color cx = bm.GetPixel(x, y);
            if(cx == oldColor)
            {
                sp.Push(new Point(x, y));
                bm.SetPixel(x, y, newColor);
            }
        }

        public void fillFigure(Bitmap bm, int x, int y, Color newColor)
        {
            Color oldColor = bm.GetPixel(x, y);
            Stack<Point> pixel = new Stack<Point>();
            pixel.Push(new Point(x, y));
            bm.SetPixel(x, y, newColor);
            if (oldColor == newColor) return;

            while(pixel.Count > 0)
            {
                Point pt = (Point)pixel.Pop();
                if(pt.X > 0 && pt.Y > 0 && pt.X < bm.Width - 1 && pt.Y < bm.Height - 1)
                {
                    validate(bm, pixel, pt.X - 1, pt.Y, oldColor, newColor);
                    validate(bm, pixel, pt.X, pt.Y - 1, oldColor, newColor);
                    validate(bm, pixel, pt.X + 1, pt.Y, oldColor, newColor);
                    validate(bm, pixel, pt.X, pt.Y + 1, oldColor, newColor);
                } 
            }
        }

        //Type line
        private void radioButtonRounded_CheckedChanged(object sender, EventArgs e)
        {
            pen.StartCap = System.Drawing.Drawing2D.LineCap.Round;
            pen.EndCap = System.Drawing.Drawing2D.LineCap.Round;
        }

        private void radioButtonSquared_CheckedChanged(object sender, EventArgs e)
        {
            pen.StartCap = System.Drawing.Drawing2D.LineCap.Square;
            pen.EndCap = System.Drawing.Drawing2D.LineCap.Square;
        }

        private void radioButtonTriangled_CheckedChanged(object sender, EventArgs e)
        {
            pen.StartCap = System.Drawing.Drawing2D.LineCap.Triangle;
            pen.EndCap = System.Drawing.Drawing2D.LineCap.Triangle;
        }

        //Draw Fourier signal
        private void buttonFourier_Click(object sender, EventArgs e)
        {
            graphics.Clear(pictureBoxMain.BackColor);
            pictureBoxMain.Image = pic;

            int acc = (int)numericUpDownFrequency.Value;
            int A = (int)numericUpDownAmplitude.Value;
            int F = (int)numericUpDownHarmonics.Value;

            int angle = 0, interval = pictureBoxMain.Width;
            double y = 0, y1, y2;

            ArrayPoints array = new ArrayPoints(interval);

            if (radioButtonRounded.Checked)
            {
                for (int i = 0; i < interval; i++)
                {
                    for (int j = 1; j < acc; j++)
                    {
                        y1 = A / ((2 * j) - 1);
                        y2 = Math.Sin(((j * 2) - 1) * F * 0.01397 * angle);
                        y += +y1 * y2;
                    }
                    array.setPoint(i, pictureBoxMain.Height / 2 + (int)Math.Truncate(y));
                    y = 0;
                    angle++;
                }
                pictureBoxMain.Image = pic;
                graphics.DrawLines(pen, array.getPoints());
            }

            if (radioButtonSquared.Checked)
            {
                for (int i = 0; i < interval; i++)
                {
                    for (int j = 1; j < acc; j++)
                    {
                        y1 = A / (((2 * j) - 1) * ((2 * j) - 1));
                        y2 = Math.Cos(((j * 2) - 1) * F * 0.01397 * angle);
                        y = y + y1 * y2;
                    }
                    array.setPoint(i, pictureBoxMain.Height / 2 + (int)Math.Truncate(y));
                    y = 0;
                    angle++;
                }
                pictureBoxMain.Image = pic;
                graphics.DrawLines(pen, array.getPoints());

            }

            if (radioButtonTriangled.Checked)
            {
                for (int i = 0; i < interval; i++)
                {
                    for (int j = 1; j < acc; j++)
                    {
                        y1 = A / j;
                        y2 = Math.Sin(j * F * 0.01397 * angle);
                        y += (+y1 * y2);
                    }
                    array.setPoint(i, pictureBoxMain.Height / 2 + (int)Math.Truncate(y));
                    y = 0;
                    angle++;
                }
                pictureBoxMain.Image = pic;
                graphics.DrawLines(pen, array.getPoints());
            }
            array.resetPoints();
        }
    }
}
