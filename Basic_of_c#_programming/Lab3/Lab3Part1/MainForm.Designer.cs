
namespace Lab3Part1
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.panelMain = new System.Windows.Forms.Panel();
            this.panelSettings = new System.Windows.Forms.Panel();
            this.labelHarmonics = new System.Windows.Forms.Label();
            this.labelAmplitude = new System.Windows.Forms.Label();
            this.labelFrequency = new System.Windows.Forms.Label();
            this.numericUpDownHarmonics = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownAmplitude = new System.Windows.Forms.NumericUpDown();
            this.numericUpDownFrequency = new System.Windows.Forms.NumericUpDown();
            this.groupBoxTypeLine = new System.Windows.Forms.GroupBox();
            this.radioButtonTriangled = new System.Windows.Forms.RadioButton();
            this.radioButtonSquared = new System.Windows.Forms.RadioButton();
            this.radioButtonRounded = new System.Windows.Forms.RadioButton();
            this.groupBoxTypeFigure = new System.Windows.Forms.GroupBox();
            this.radioButtonEllipse = new System.Windows.Forms.RadioButton();
            this.radioButtonRectangle = new System.Windows.Forms.RadioButton();
            this.radioButtonRuler = new System.Windows.Forms.RadioButton();
            this.panelSettingLine = new System.Windows.Forms.Panel();
            this.labelThickness = new System.Windows.Forms.Label();
            this.trackBar1 = new System.Windows.Forms.TrackBar();
            this.flowLayoutPanel1 = new System.Windows.Forms.FlowLayoutPanel();
            this.buttonWhite = new System.Windows.Forms.Button();
            this.buttonBlack = new System.Windows.Forms.Button();
            this.buttonRed = new System.Windows.Forms.Button();
            this.buttonYellow = new System.Windows.Forms.Button();
            this.buttonGreen = new System.Windows.Forms.Button();
            this.buttonPurple = new System.Windows.Forms.Button();
            this.buttonOrange = new System.Windows.Forms.Button();
            this.buttonLightBlue = new System.Windows.Forms.Button();
            this.buttonBlue = new System.Windows.Forms.Button();
            this.buttonDefaultColor = new System.Windows.Forms.Button();
            this.buttonPen = new System.Windows.Forms.Button();
            this.buttonPouring = new System.Windows.Forms.Button();
            this.buttonErase = new System.Windows.Forms.Button();
            this.buttonFourier = new System.Windows.Forms.Button();
            this.pictureBoxMain = new System.Windows.Forms.PictureBox();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.createToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exiteToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.colorDialogForPen = new System.Windows.Forms.ColorDialog();
            this.colorDialogForBackground = new System.Windows.Forms.ColorDialog();
            this.panelMain.SuspendLayout();
            this.panelSettings.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownHarmonics)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownAmplitude)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownFrequency)).BeginInit();
            this.groupBoxTypeLine.SuspendLayout();
            this.groupBoxTypeFigure.SuspendLayout();
            this.panelSettingLine.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).BeginInit();
            this.flowLayoutPanel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxMain)).BeginInit();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // panelMain
            // 
            this.panelMain.Controls.Add(this.panelSettings);
            this.panelMain.Controls.Add(this.pictureBoxMain);
            this.panelMain.Controls.Add(this.menuStrip1);
            this.panelMain.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panelMain.Location = new System.Drawing.Point(0, 0);
            this.panelMain.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.panelMain.Name = "panelMain";
            this.panelMain.Size = new System.Drawing.Size(1581, 812);
            this.panelMain.TabIndex = 0;
            // 
            // panelSettings
            // 
            this.panelSettings.Controls.Add(this.labelHarmonics);
            this.panelSettings.Controls.Add(this.labelAmplitude);
            this.panelSettings.Controls.Add(this.labelFrequency);
            this.panelSettings.Controls.Add(this.numericUpDownHarmonics);
            this.panelSettings.Controls.Add(this.numericUpDownAmplitude);
            this.panelSettings.Controls.Add(this.numericUpDownFrequency);
            this.panelSettings.Controls.Add(this.groupBoxTypeLine);
            this.panelSettings.Controls.Add(this.groupBoxTypeFigure);
            this.panelSettings.Controls.Add(this.panelSettingLine);
            this.panelSettings.Controls.Add(this.flowLayoutPanel1);
            this.panelSettings.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelSettings.Location = new System.Drawing.Point(0, 24);
            this.panelSettings.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.panelSettings.Name = "panelSettings";
            this.panelSettings.Size = new System.Drawing.Size(1581, 101);
            this.panelSettings.TabIndex = 2;
            // 
            // labelHarmonics
            // 
            this.labelHarmonics.AutoSize = true;
            this.labelHarmonics.Font = new System.Drawing.Font("Comic Sans MS", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelHarmonics.Location = new System.Drawing.Point(1405, 74);
            this.labelHarmonics.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labelHarmonics.Name = "labelHarmonics";
            this.labelHarmonics.Size = new System.Drawing.Size(71, 18);
            this.labelHarmonics.TabIndex = 9;
            this.labelHarmonics.Text = "Harmonics";
            // 
            // labelAmplitude
            // 
            this.labelAmplitude.AutoSize = true;
            this.labelAmplitude.Font = new System.Drawing.Font("Comic Sans MS", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelAmplitude.Location = new System.Drawing.Point(1405, 46);
            this.labelAmplitude.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labelAmplitude.Name = "labelAmplitude";
            this.labelAmplitude.Size = new System.Drawing.Size(68, 18);
            this.labelAmplitude.TabIndex = 8;
            this.labelAmplitude.Text = "Amplitude";
            // 
            // labelFrequency
            // 
            this.labelFrequency.AutoSize = true;
            this.labelFrequency.Font = new System.Drawing.Font("Comic Sans MS", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelFrequency.Location = new System.Drawing.Point(1405, 15);
            this.labelFrequency.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labelFrequency.Name = "labelFrequency";
            this.labelFrequency.Size = new System.Drawing.Size(71, 18);
            this.labelFrequency.TabIndex = 7;
            this.labelFrequency.Text = "Frequency";
            // 
            // numericUpDownHarmonics
            // 
            this.numericUpDownHarmonics.Location = new System.Drawing.Point(1237, 71);
            this.numericUpDownHarmonics.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.numericUpDownHarmonics.Name = "numericUpDownHarmonics";
            this.numericUpDownHarmonics.Size = new System.Drawing.Size(160, 22);
            this.numericUpDownHarmonics.TabIndex = 6;
            // 
            // numericUpDownAmplitude
            // 
            this.numericUpDownAmplitude.Location = new System.Drawing.Point(1237, 43);
            this.numericUpDownAmplitude.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.numericUpDownAmplitude.Name = "numericUpDownAmplitude";
            this.numericUpDownAmplitude.Size = new System.Drawing.Size(160, 22);
            this.numericUpDownAmplitude.TabIndex = 5;
            // 
            // numericUpDownFrequency
            // 
            this.numericUpDownFrequency.Location = new System.Drawing.Point(1237, 15);
            this.numericUpDownFrequency.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.numericUpDownFrequency.Name = "numericUpDownFrequency";
            this.numericUpDownFrequency.Size = new System.Drawing.Size(160, 22);
            this.numericUpDownFrequency.TabIndex = 4;
            // 
            // groupBoxTypeLine
            // 
            this.groupBoxTypeLine.Controls.Add(this.radioButtonTriangled);
            this.groupBoxTypeLine.Controls.Add(this.radioButtonSquared);
            this.groupBoxTypeLine.Controls.Add(this.radioButtonRounded);
            this.groupBoxTypeLine.Location = new System.Drawing.Point(961, 6);
            this.groupBoxTypeLine.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.groupBoxTypeLine.Name = "groupBoxTypeLine";
            this.groupBoxTypeLine.Padding = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.groupBoxTypeLine.Size = new System.Drawing.Size(267, 95);
            this.groupBoxTypeLine.TabIndex = 3;
            this.groupBoxTypeLine.TabStop = false;
            // 
            // radioButtonTriangled
            // 
            this.radioButtonTriangled.AutoSize = true;
            this.radioButtonTriangled.Font = new System.Drawing.Font("Comic Sans MS", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.radioButtonTriangled.Location = new System.Drawing.Point(5, 65);
            this.radioButtonTriangled.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.radioButtonTriangled.Name = "radioButtonTriangled";
            this.radioButtonTriangled.Size = new System.Drawing.Size(103, 22);
            this.radioButtonTriangled.TabIndex = 2;
            this.radioButtonTriangled.TabStop = true;
            this.radioButtonTriangled.Text = "Triangle line";
            this.radioButtonTriangled.UseVisualStyleBackColor = true;
            this.radioButtonTriangled.CheckedChanged += new System.EventHandler(this.radioButtonTriangled_CheckedChanged);
            // 
            // radioButtonSquared
            // 
            this.radioButtonSquared.AutoSize = true;
            this.radioButtonSquared.Font = new System.Drawing.Font("Comic Sans MS", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.radioButtonSquared.Location = new System.Drawing.Point(5, 37);
            this.radioButtonSquared.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.radioButtonSquared.Name = "radioButtonSquared";
            this.radioButtonSquared.Size = new System.Drawing.Size(103, 22);
            this.radioButtonSquared.TabIndex = 1;
            this.radioButtonSquared.TabStop = true;
            this.radioButtonSquared.Text = "Squared line";
            this.radioButtonSquared.UseVisualStyleBackColor = true;
            this.radioButtonSquared.CheckedChanged += new System.EventHandler(this.radioButtonSquared_CheckedChanged);
            // 
            // radioButtonRounded
            // 
            this.radioButtonRounded.AutoSize = true;
            this.radioButtonRounded.Font = new System.Drawing.Font("Comic Sans MS", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.radioButtonRounded.Location = new System.Drawing.Point(5, 9);
            this.radioButtonRounded.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.radioButtonRounded.Name = "radioButtonRounded";
            this.radioButtonRounded.Size = new System.Drawing.Size(104, 22);
            this.radioButtonRounded.TabIndex = 0;
            this.radioButtonRounded.TabStop = true;
            this.radioButtonRounded.Text = "Rounded line";
            this.radioButtonRounded.UseVisualStyleBackColor = true;
            this.radioButtonRounded.CheckedChanged += new System.EventHandler(this.radioButtonRounded_CheckedChanged);
            // 
            // groupBoxTypeFigure
            // 
            this.groupBoxTypeFigure.Controls.Add(this.radioButtonEllipse);
            this.groupBoxTypeFigure.Controls.Add(this.radioButtonRectangle);
            this.groupBoxTypeFigure.Controls.Add(this.radioButtonRuler);
            this.groupBoxTypeFigure.Location = new System.Drawing.Point(687, 6);
            this.groupBoxTypeFigure.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.groupBoxTypeFigure.Name = "groupBoxTypeFigure";
            this.groupBoxTypeFigure.Padding = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.groupBoxTypeFigure.Size = new System.Drawing.Size(267, 91);
            this.groupBoxTypeFigure.TabIndex = 2;
            this.groupBoxTypeFigure.TabStop = false;
            // 
            // radioButtonEllipse
            // 
            this.radioButtonEllipse.AutoSize = true;
            this.radioButtonEllipse.Font = new System.Drawing.Font("Comic Sans MS", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.radioButtonEllipse.Location = new System.Drawing.Point(9, 65);
            this.radioButtonEllipse.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.radioButtonEllipse.Name = "radioButtonEllipse";
            this.radioButtonEllipse.Size = new System.Drawing.Size(66, 22);
            this.radioButtonEllipse.TabIndex = 2;
            this.radioButtonEllipse.TabStop = true;
            this.radioButtonEllipse.Text = "Ellipse";
            this.radioButtonEllipse.UseVisualStyleBackColor = true;
            this.radioButtonEllipse.CheckedChanged += new System.EventHandler(this.radioButtonEllipse_CheckedChanged);
            // 
            // radioButtonRectangle
            // 
            this.radioButtonRectangle.AutoSize = true;
            this.radioButtonRectangle.Font = new System.Drawing.Font("Comic Sans MS", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.radioButtonRectangle.Location = new System.Drawing.Point(9, 37);
            this.radioButtonRectangle.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.radioButtonRectangle.Name = "radioButtonRectangle";
            this.radioButtonRectangle.Size = new System.Drawing.Size(85, 22);
            this.radioButtonRectangle.TabIndex = 1;
            this.radioButtonRectangle.TabStop = true;
            this.radioButtonRectangle.Text = "Rectangle";
            this.radioButtonRectangle.UseVisualStyleBackColor = true;
            this.radioButtonRectangle.CheckedChanged += new System.EventHandler(this.radioButtonRectangle_CheckedChanged);
            // 
            // radioButtonRuler
            // 
            this.radioButtonRuler.AutoSize = true;
            this.radioButtonRuler.Font = new System.Drawing.Font("Comic Sans MS", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.radioButtonRuler.Location = new System.Drawing.Point(9, 9);
            this.radioButtonRuler.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.radioButtonRuler.Name = "radioButtonRuler";
            this.radioButtonRuler.Size = new System.Drawing.Size(58, 22);
            this.radioButtonRuler.TabIndex = 0;
            this.radioButtonRuler.TabStop = true;
            this.radioButtonRuler.Text = "Ruler";
            this.radioButtonRuler.UseVisualStyleBackColor = true;
            this.radioButtonRuler.CheckedChanged += new System.EventHandler(this.radioButtonRuler_CheckedChanged_1);
            // 
            // panelSettingLine
            // 
            this.panelSettingLine.Controls.Add(this.labelThickness);
            this.panelSettingLine.Controls.Add(this.trackBar1);
            this.panelSettingLine.Dock = System.Windows.Forms.DockStyle.Left;
            this.panelSettingLine.Location = new System.Drawing.Point(487, 0);
            this.panelSettingLine.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.panelSettingLine.Name = "panelSettingLine";
            this.panelSettingLine.Size = new System.Drawing.Size(173, 101);
            this.panelSettingLine.TabIndex = 1;
            // 
            // labelThickness
            // 
            this.labelThickness.AutoSize = true;
            this.labelThickness.Dock = System.Windows.Forms.DockStyle.Left;
            this.labelThickness.Font = new System.Drawing.Font("Comic Sans MS", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelThickness.Location = new System.Drawing.Point(0, 0);
            this.labelThickness.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labelThickness.Name = "labelThickness";
            this.labelThickness.Size = new System.Drawing.Size(124, 23);
            this.labelThickness.TabIndex = 2;
            this.labelThickness.Text = "Pencil thickness";
            // 
            // trackBar1
            // 
            this.trackBar1.Location = new System.Drawing.Point(4, 42);
            this.trackBar1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.trackBar1.Name = "trackBar1";
            this.trackBar1.Size = new System.Drawing.Size(139, 45);
            this.trackBar1.TabIndex = 0;
            this.trackBar1.ValueChanged += new System.EventHandler(this.trackBar1_ValueChanged);
            // 
            // flowLayoutPanel1
            // 
            this.flowLayoutPanel1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.flowLayoutPanel1.Controls.Add(this.buttonWhite);
            this.flowLayoutPanel1.Controls.Add(this.buttonBlack);
            this.flowLayoutPanel1.Controls.Add(this.buttonRed);
            this.flowLayoutPanel1.Controls.Add(this.buttonYellow);
            this.flowLayoutPanel1.Controls.Add(this.buttonGreen);
            this.flowLayoutPanel1.Controls.Add(this.buttonPurple);
            this.flowLayoutPanel1.Controls.Add(this.buttonOrange);
            this.flowLayoutPanel1.Controls.Add(this.buttonLightBlue);
            this.flowLayoutPanel1.Controls.Add(this.buttonBlue);
            this.flowLayoutPanel1.Controls.Add(this.buttonDefaultColor);
            this.flowLayoutPanel1.Controls.Add(this.buttonPen);
            this.flowLayoutPanel1.Controls.Add(this.buttonPouring);
            this.flowLayoutPanel1.Controls.Add(this.buttonErase);
            this.flowLayoutPanel1.Controls.Add(this.buttonFourier);
            this.flowLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Left;
            this.flowLayoutPanel1.Location = new System.Drawing.Point(0, 0);
            this.flowLayoutPanel1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.flowLayoutPanel1.Name = "flowLayoutPanel1";
            this.flowLayoutPanel1.Size = new System.Drawing.Size(487, 101);
            this.flowLayoutPanel1.TabIndex = 0;
            // 
            // buttonWhite
            // 
            this.buttonWhite.BackColor = System.Drawing.Color.White;
            this.buttonWhite.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonWhite.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonWhite.Location = new System.Drawing.Point(4, 4);
            this.buttonWhite.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonWhite.Name = "buttonWhite";
            this.buttonWhite.Size = new System.Drawing.Size(40, 37);
            this.buttonWhite.TabIndex = 0;
            this.buttonWhite.UseVisualStyleBackColor = false;
            this.buttonWhite.Click += new System.EventHandler(this.buttonWhite_Click);
            // 
            // buttonBlack
            // 
            this.buttonBlack.BackColor = System.Drawing.Color.Black;
            this.buttonBlack.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonBlack.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonBlack.Location = new System.Drawing.Point(52, 4);
            this.buttonBlack.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonBlack.Name = "buttonBlack";
            this.buttonBlack.Size = new System.Drawing.Size(40, 37);
            this.buttonBlack.TabIndex = 1;
            this.buttonBlack.UseVisualStyleBackColor = false;
            this.buttonBlack.Click += new System.EventHandler(this.buttonWhite_Click);
            // 
            // buttonRed
            // 
            this.buttonRed.BackColor = System.Drawing.Color.Red;
            this.buttonRed.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonRed.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonRed.Location = new System.Drawing.Point(100, 4);
            this.buttonRed.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonRed.Name = "buttonRed";
            this.buttonRed.Size = new System.Drawing.Size(40, 37);
            this.buttonRed.TabIndex = 2;
            this.buttonRed.UseVisualStyleBackColor = false;
            this.buttonRed.Click += new System.EventHandler(this.buttonWhite_Click);
            // 
            // buttonYellow
            // 
            this.buttonYellow.BackColor = System.Drawing.Color.Yellow;
            this.buttonYellow.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonYellow.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonYellow.Location = new System.Drawing.Point(148, 4);
            this.buttonYellow.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonYellow.Name = "buttonYellow";
            this.buttonYellow.Size = new System.Drawing.Size(40, 37);
            this.buttonYellow.TabIndex = 3;
            this.buttonYellow.UseVisualStyleBackColor = false;
            this.buttonYellow.Click += new System.EventHandler(this.buttonWhite_Click);
            // 
            // buttonGreen
            // 
            this.buttonGreen.BackColor = System.Drawing.Color.Green;
            this.buttonGreen.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonGreen.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonGreen.Location = new System.Drawing.Point(196, 4);
            this.buttonGreen.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonGreen.Name = "buttonGreen";
            this.buttonGreen.Size = new System.Drawing.Size(40, 37);
            this.buttonGreen.TabIndex = 4;
            this.buttonGreen.UseVisualStyleBackColor = false;
            this.buttonGreen.Click += new System.EventHandler(this.buttonWhite_Click);
            // 
            // buttonPurple
            // 
            this.buttonPurple.BackColor = System.Drawing.Color.Purple;
            this.buttonPurple.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonPurple.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonPurple.Location = new System.Drawing.Point(244, 4);
            this.buttonPurple.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonPurple.Name = "buttonPurple";
            this.buttonPurple.Size = new System.Drawing.Size(40, 37);
            this.buttonPurple.TabIndex = 5;
            this.buttonPurple.UseVisualStyleBackColor = false;
            this.buttonPurple.Click += new System.EventHandler(this.buttonWhite_Click);
            // 
            // buttonOrange
            // 
            this.buttonOrange.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(0)))));
            this.buttonOrange.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonOrange.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonOrange.Location = new System.Drawing.Point(292, 4);
            this.buttonOrange.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonOrange.Name = "buttonOrange";
            this.buttonOrange.Size = new System.Drawing.Size(40, 37);
            this.buttonOrange.TabIndex = 6;
            this.buttonOrange.UseVisualStyleBackColor = false;
            this.buttonOrange.Click += new System.EventHandler(this.buttonWhite_Click);
            // 
            // buttonLightBlue
            // 
            this.buttonLightBlue.BackColor = System.Drawing.Color.LightSkyBlue;
            this.buttonLightBlue.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonLightBlue.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonLightBlue.Location = new System.Drawing.Point(340, 4);
            this.buttonLightBlue.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonLightBlue.Name = "buttonLightBlue";
            this.buttonLightBlue.Size = new System.Drawing.Size(40, 37);
            this.buttonLightBlue.TabIndex = 7;
            this.buttonLightBlue.UseVisualStyleBackColor = false;
            this.buttonLightBlue.Click += new System.EventHandler(this.buttonWhite_Click);
            // 
            // buttonBlue
            // 
            this.buttonBlue.BackColor = System.Drawing.Color.Blue;
            this.buttonBlue.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonBlue.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonBlue.Location = new System.Drawing.Point(388, 4);
            this.buttonBlue.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonBlue.Name = "buttonBlue";
            this.buttonBlue.Size = new System.Drawing.Size(40, 37);
            this.buttonBlue.TabIndex = 8;
            this.buttonBlue.UseVisualStyleBackColor = false;
            this.buttonBlue.Click += new System.EventHandler(this.buttonWhite_Click);
            // 
            // buttonDefaultColor
            // 
            this.buttonDefaultColor.BackColor = System.Drawing.Color.Transparent;
            this.buttonDefaultColor.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonDefaultColor.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonDefaultColor.Location = new System.Drawing.Point(436, 4);
            this.buttonDefaultColor.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonDefaultColor.Name = "buttonDefaultColor";
            this.buttonDefaultColor.Size = new System.Drawing.Size(40, 37);
            this.buttonDefaultColor.TabIndex = 9;
            this.buttonDefaultColor.UseVisualStyleBackColor = false;
            this.buttonDefaultColor.Click += new System.EventHandler(this.buttonDefaultColor_Click);
            // 
            // buttonPen
            // 
            this.buttonPen.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("buttonPen.BackgroundImage")));
            this.buttonPen.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.buttonPen.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonPen.Location = new System.Drawing.Point(4, 49);
            this.buttonPen.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonPen.Name = "buttonPen";
            this.buttonPen.Size = new System.Drawing.Size(40, 37);
            this.buttonPen.TabIndex = 10;
            this.buttonPen.UseVisualStyleBackColor = true;
            this.buttonPen.Click += new System.EventHandler(this.buttonPen_Click);
            // 
            // buttonPouring
            // 
            this.buttonPouring.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("buttonPouring.BackgroundImage")));
            this.buttonPouring.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.buttonPouring.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonPouring.Location = new System.Drawing.Point(52, 49);
            this.buttonPouring.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonPouring.Name = "buttonPouring";
            this.buttonPouring.Size = new System.Drawing.Size(40, 37);
            this.buttonPouring.TabIndex = 11;
            this.buttonPouring.UseVisualStyleBackColor = true;
            this.buttonPouring.Click += new System.EventHandler(this.buttonPouring_Click);
            // 
            // buttonErase
            // 
            this.buttonErase.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("buttonErase.BackgroundImage")));
            this.buttonErase.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.buttonErase.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonErase.Location = new System.Drawing.Point(100, 49);
            this.buttonErase.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonErase.Name = "buttonErase";
            this.buttonErase.Size = new System.Drawing.Size(40, 37);
            this.buttonErase.TabIndex = 12;
            this.buttonErase.UseVisualStyleBackColor = true;
            this.buttonErase.Click += new System.EventHandler(this.buttonErase_Click);
            // 
            // buttonFourier
            // 
            this.buttonFourier.Font = new System.Drawing.Font("Comic Sans MS", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonFourier.Location = new System.Drawing.Point(148, 49);
            this.buttonFourier.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonFourier.Name = "buttonFourier";
            this.buttonFourier.Size = new System.Drawing.Size(280, 37);
            this.buttonFourier.TabIndex = 3;
            this.buttonFourier.Text = "Fourier signals";
            this.buttonFourier.UseVisualStyleBackColor = true;
            this.buttonFourier.Click += new System.EventHandler(this.buttonFourier_Click);
            // 
            // pictureBoxMain
            // 
            this.pictureBoxMain.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.pictureBoxMain.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pictureBoxMain.Location = new System.Drawing.Point(0, 138);
            this.pictureBoxMain.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.pictureBoxMain.Name = "pictureBoxMain";
            this.pictureBoxMain.Size = new System.Drawing.Size(1581, 674);
            this.pictureBoxMain.TabIndex = 1;
            this.pictureBoxMain.TabStop = false;
            this.pictureBoxMain.Paint += new System.Windows.Forms.PaintEventHandler(this.pictureBoxMain_Paint);
            this.pictureBoxMain.MouseClick += new System.Windows.Forms.MouseEventHandler(this.pictureBoxMain_MouseClick);
            this.pictureBoxMain.MouseDown += new System.Windows.Forms.MouseEventHandler(this.pictureBoxMain_MouseDown);
            this.pictureBoxMain.MouseMove += new System.Windows.Forms.MouseEventHandler(this.pictureBoxMain_MouseMove);
            this.pictureBoxMain.MouseUp += new System.Windows.Forms.MouseEventHandler(this.pictureBoxMain_MouseUp);
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Padding = new System.Windows.Forms.Padding(8, 2, 0, 2);
            this.menuStrip1.Size = new System.Drawing.Size(1581, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.createToolStripMenuItem,
            this.saveToolStripMenuItem,
            this.openToolStripMenuItem,
            this.exiteToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // createToolStripMenuItem
            // 
            this.createToolStripMenuItem.Name = "createToolStripMenuItem";
            this.createToolStripMenuItem.Size = new System.Drawing.Size(108, 22);
            this.createToolStripMenuItem.Text = "Create";
            this.createToolStripMenuItem.Click += new System.EventHandler(this.createToolStripMenuItem_Click);
            // 
            // saveToolStripMenuItem
            // 
            this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
            this.saveToolStripMenuItem.Size = new System.Drawing.Size(108, 22);
            this.saveToolStripMenuItem.Text = "Save";
            this.saveToolStripMenuItem.Click += new System.EventHandler(this.saveToolStripMenuItem_Click);
            // 
            // openToolStripMenuItem
            // 
            this.openToolStripMenuItem.Name = "openToolStripMenuItem";
            this.openToolStripMenuItem.Size = new System.Drawing.Size(108, 22);
            this.openToolStripMenuItem.Text = "Open";
            this.openToolStripMenuItem.Click += new System.EventHandler(this.openToolStripMenuItem_Click);
            // 
            // exiteToolStripMenuItem
            // 
            this.exiteToolStripMenuItem.Name = "exiteToolStripMenuItem";
            this.exiteToolStripMenuItem.Size = new System.Drawing.Size(108, 22);
            this.exiteToolStripMenuItem.Text = "Exit";
            this.exiteToolStripMenuItem.Click += new System.EventHandler(this.exiteToolStripMenuItem_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1581, 812);
            this.Controls.Add(this.panelMain);
            this.MainMenuStrip = this.menuStrip1;
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "MainForm";
            this.Text = "Form1";
            this.panelMain.ResumeLayout(false);
            this.panelMain.PerformLayout();
            this.panelSettings.ResumeLayout(false);
            this.panelSettings.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownHarmonics)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownAmplitude)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownFrequency)).EndInit();
            this.groupBoxTypeLine.ResumeLayout(false);
            this.groupBoxTypeLine.PerformLayout();
            this.groupBoxTypeFigure.ResumeLayout(false);
            this.groupBoxTypeFigure.PerformLayout();
            this.panelSettingLine.ResumeLayout(false);
            this.panelSettingLine.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).EndInit();
            this.flowLayoutPanel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxMain)).EndInit();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panelMain;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem createToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem openToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exiteToolStripMenuItem;
        private System.Windows.Forms.Panel panelSettings;
        private System.Windows.Forms.Panel panelSettingLine;
        private System.Windows.Forms.Label labelThickness;
        private System.Windows.Forms.TrackBar trackBar1;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel1;
        private System.Windows.Forms.Button buttonWhite;
        private System.Windows.Forms.Button buttonBlack;
        private System.Windows.Forms.Button buttonRed;
        private System.Windows.Forms.Button buttonYellow;
        private System.Windows.Forms.Button buttonGreen;
        private System.Windows.Forms.Button buttonPurple;
        private System.Windows.Forms.Button buttonOrange;
        private System.Windows.Forms.Button buttonLightBlue;
        private System.Windows.Forms.Button buttonBlue;
        private System.Windows.Forms.Button buttonDefaultColor;
        private System.Windows.Forms.PictureBox pictureBoxMain;
        private System.Windows.Forms.ColorDialog colorDialogForPen;
        private System.Windows.Forms.Button buttonPen;
        private System.Windows.Forms.Button buttonPouring;
        private System.Windows.Forms.GroupBox groupBoxTypeFigure;
        private System.Windows.Forms.RadioButton radioButtonEllipse;
        private System.Windows.Forms.RadioButton radioButtonRectangle;
        private System.Windows.Forms.RadioButton radioButtonRuler;
        private System.Windows.Forms.ColorDialog colorDialogForBackground;
        private System.Windows.Forms.GroupBox groupBoxTypeLine;
        private System.Windows.Forms.RadioButton radioButtonTriangled;
        private System.Windows.Forms.RadioButton radioButtonSquared;
        private System.Windows.Forms.RadioButton radioButtonRounded;
        private System.Windows.Forms.Button buttonFourier;
        private System.Windows.Forms.Label labelHarmonics;
        private System.Windows.Forms.Label labelAmplitude;
        private System.Windows.Forms.Label labelFrequency;
        private System.Windows.Forms.NumericUpDown numericUpDownHarmonics;
        private System.Windows.Forms.NumericUpDown numericUpDownAmplitude;
        private System.Windows.Forms.NumericUpDown numericUpDownFrequency;
        private System.Windows.Forms.Button buttonErase;
    }
}

