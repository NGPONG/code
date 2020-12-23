namespace 音乐播放器
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.musicPlayer = new AxWMPLib.AxWindowsMediaPlayer();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.musicStop = new System.Windows.Forms.Button();
            this.musicPause = new System.Windows.Forms.Button();
            this.musicPlay = new System.Windows.Forms.Button();
            this.musicPlayOrPause = new System.Windows.Forms.Button();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.musicSelect = new System.Windows.Forms.Button();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.删除ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.没做ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.musicNext = new System.Windows.Forms.Button();
            this.musicLast = new System.Windows.Forms.Button();
            this.btnMusicUp = new System.Windows.Forms.Button();
            this.btnMusicDown = new System.Windows.Forms.Button();
            this.btnMute = new System.Windows.Forms.Button();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.timer2 = new System.Windows.Forms.Timer(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.musicPlayer)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.contextMenuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // musicPlayer
            // 
            this.musicPlayer.Enabled = true;
            this.musicPlayer.Location = new System.Drawing.Point(12, 12);
            this.musicPlayer.Name = "musicPlayer";
            this.musicPlayer.OcxState = ((System.Windows.Forms.AxHost.State)(resources.GetObject("musicPlayer.OcxState")));
            this.musicPlayer.Size = new System.Drawing.Size(632, 184);
            this.musicPlayer.TabIndex = 0;
            this.musicPlayer.PlayStateChange += new AxWMPLib._WMPOCXEvents_PlayStateChangeEventHandler(this.musicPlayer_PlayStateChange);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.musicStop);
            this.groupBox1.Controls.Add(this.musicPause);
            this.groupBox1.Controls.Add(this.musicPlay);
            this.groupBox1.Location = new System.Drawing.Point(534, 211);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(110, 184);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "老版播放器";
            // 
            // musicStop
            // 
            this.musicStop.Location = new System.Drawing.Point(18, 126);
            this.musicStop.Name = "musicStop";
            this.musicStop.Size = new System.Drawing.Size(75, 23);
            this.musicStop.TabIndex = 2;
            this.musicStop.Text = "停止";
            this.musicStop.UseVisualStyleBackColor = true;
            this.musicStop.Click += new System.EventHandler(this.musicStop_Click);
            // 
            // musicPause
            // 
            this.musicPause.Location = new System.Drawing.Point(18, 74);
            this.musicPause.Name = "musicPause";
            this.musicPause.Size = new System.Drawing.Size(75, 23);
            this.musicPause.TabIndex = 1;
            this.musicPause.Text = "暂停";
            this.musicPause.UseVisualStyleBackColor = true;
            this.musicPause.Click += new System.EventHandler(this.musicPause_Click);
            // 
            // musicPlay
            // 
            this.musicPlay.Location = new System.Drawing.Point(18, 30);
            this.musicPlay.Name = "musicPlay";
            this.musicPlay.Size = new System.Drawing.Size(75, 23);
            this.musicPlay.TabIndex = 0;
            this.musicPlay.Text = "播放";
            this.musicPlay.UseVisualStyleBackColor = true;
            this.musicPlay.Click += new System.EventHandler(this.musicPlay_Click);
            // 
            // musicPlayOrPause
            // 
            this.musicPlayOrPause.Location = new System.Drawing.Point(68, 211);
            this.musicPlayOrPause.Name = "musicPlayOrPause";
            this.musicPlayOrPause.Size = new System.Drawing.Size(75, 23);
            this.musicPlayOrPause.TabIndex = 2;
            this.musicPlayOrPause.Text = "播放";
            this.musicPlayOrPause.UseVisualStyleBackColor = true;
            this.musicPlayOrPause.Click += new System.EventHandler(this.musicPlayOrPause_Click);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            this.openFileDialog1.FileOk += new System.ComponentModel.CancelEventHandler(this.openFileDialog1_FileOk);
            // 
            // musicSelect
            // 
            this.musicSelect.Location = new System.Drawing.Point(158, 394);
            this.musicSelect.Name = "musicSelect";
            this.musicSelect.Size = new System.Drawing.Size(75, 23);
            this.musicSelect.TabIndex = 3;
            this.musicSelect.Text = "选择文件";
            this.musicSelect.UseVisualStyleBackColor = true;
            this.musicSelect.Click += new System.EventHandler(this.musicSelect_Click);
            // 
            // listBox1
            // 
            this.listBox1.ContextMenuStrip = this.contextMenuStrip1;
            this.listBox1.FormattingEnabled = true;
            this.listBox1.ItemHeight = 12;
            this.listBox1.Location = new System.Drawing.Point(13, 257);
            this.listBox1.Name = "listBox1";
            this.listBox1.SelectionMode = System.Windows.Forms.SelectionMode.MultiExtended;
            this.listBox1.Size = new System.Drawing.Size(130, 160);
            this.listBox1.TabIndex = 4;
            this.listBox1.DoubleClick += new System.EventHandler(this.listBox1_DoubleClick);
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.删除ToolStripMenuItem,
            this.没做ToolStripMenuItem});
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(101, 48);
            // 
            // 删除ToolStripMenuItem
            // 
            this.删除ToolStripMenuItem.Name = "删除ToolStripMenuItem";
            this.删除ToolStripMenuItem.Size = new System.Drawing.Size(100, 22);
            this.删除ToolStripMenuItem.Text = "删除";
            this.删除ToolStripMenuItem.Click += new System.EventHandler(this.删除ToolStripMenuItem_Click);
            // 
            // 没做ToolStripMenuItem
            // 
            this.没做ToolStripMenuItem.Name = "没做ToolStripMenuItem";
            this.没做ToolStripMenuItem.Size = new System.Drawing.Size(100, 22);
            this.没做ToolStripMenuItem.Text = "没做";
            // 
            // musicNext
            // 
            this.musicNext.Location = new System.Drawing.Point(158, 314);
            this.musicNext.Name = "musicNext";
            this.musicNext.Size = new System.Drawing.Size(75, 23);
            this.musicNext.TabIndex = 5;
            this.musicNext.Text = "上一首";
            this.musicNext.UseVisualStyleBackColor = true;
            this.musicNext.Click += new System.EventHandler(this.musicNext_Click);
            // 
            // musicLast
            // 
            this.musicLast.Location = new System.Drawing.Point(158, 358);
            this.musicLast.Name = "musicLast";
            this.musicLast.Size = new System.Drawing.Size(75, 23);
            this.musicLast.TabIndex = 6;
            this.musicLast.Text = "下一首";
            this.musicLast.UseVisualStyleBackColor = true;
            this.musicLast.Click += new System.EventHandler(this.musicLast_Click);
            // 
            // btnMusicUp
            // 
            this.btnMusicUp.Location = new System.Drawing.Point(158, 211);
            this.btnMusicUp.Name = "btnMusicUp";
            this.btnMusicUp.Size = new System.Drawing.Size(75, 23);
            this.btnMusicUp.TabIndex = 7;
            this.btnMusicUp.Text = "音量+";
            this.btnMusicUp.UseVisualStyleBackColor = true;
            this.btnMusicUp.Click += new System.EventHandler(this.btnMusicUp_Click);
            // 
            // btnMusicDown
            // 
            this.btnMusicDown.Location = new System.Drawing.Point(251, 211);
            this.btnMusicDown.Name = "btnMusicDown";
            this.btnMusicDown.Size = new System.Drawing.Size(75, 23);
            this.btnMusicDown.TabIndex = 8;
            this.btnMusicDown.Text = "音量-";
            this.btnMusicDown.UseVisualStyleBackColor = true;
            this.btnMusicDown.Click += new System.EventHandler(this.btnMusicDown_Click);
            // 
            // btnMute
            // 
            this.btnMute.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnMute.Location = new System.Drawing.Point(13, 200);
            this.btnMute.Name = "btnMute";
            this.btnMute.Size = new System.Drawing.Size(40, 45);
            this.btnMute.TabIndex = 9;
            this.btnMute.Tag = "1";
            this.btnMute.UseVisualStyleBackColor = true;
            this.btnMute.Click += new System.EventHandler(this.button1_Click);
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(365, 211);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(41, 12);
            this.label1.TabIndex = 10;
            this.label1.Text = "label1";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("微软雅黑", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label2.ForeColor = System.Drawing.Color.Red;
            this.label2.Location = new System.Drawing.Point(271, 273);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(55, 21);
            this.label2.TabIndex = 11;
            this.label2.Text = "label2";
            // 
            // timer2
            // 
            this.timer2.Enabled = true;
            this.timer2.Interval = 10;
            this.timer2.Tick += new System.EventHandler(this.timer2_Tick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(648, 429);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.btnMute);
            this.Controls.Add(this.btnMusicDown);
            this.Controls.Add(this.btnMusicUp);
            this.Controls.Add(this.musicLast);
            this.Controls.Add(this.musicNext);
            this.Controls.Add(this.listBox1);
            this.Controls.Add(this.musicSelect);
            this.Controls.Add(this.musicPlayOrPause);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.musicPlayer);
            this.Cursor = System.Windows.Forms.Cursors.Default;
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.musicPlayer)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.contextMenuStrip1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private AxWMPLib.AxWindowsMediaPlayer musicPlayer;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button musicStop;
        private System.Windows.Forms.Button musicPause;
        private System.Windows.Forms.Button musicPlay;
        private System.Windows.Forms.Button musicPlayOrPause;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.Button musicSelect;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Button musicNext;
        private System.Windows.Forms.Button musicLast;
        private System.Windows.Forms.Button btnMusicUp;
        private System.Windows.Forms.Button btnMusicDown;
        private System.Windows.Forms.Button btnMute;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 删除ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 没做ToolStripMenuItem;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Timer timer2;
    }
}

