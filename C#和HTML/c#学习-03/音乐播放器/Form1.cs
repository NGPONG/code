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

namespace 音乐播放器
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //取消meida player 播放器控件的自动播放功能
            musicPlayer.settings.autoStart = false;
            ////赋值初始歌曲的目录
            //musicPlayer.URL = @"D:\CloudMusic\Hello Nico - 接下来如何.mp3";

            //初始化打开对话框
            openFileDialog1.Multiselect = true;
            openFileDialog1.InitialDirectory = @"D:\CloudMusic";
            openFileDialog1.Title = "请选择需要播放的音乐文件";
            openFileDialog1.Filter = "音乐文件|*.mp3|歌词文件|*.lrc|所有文件|*.*";

            btnMute.Image = Image.FromFile(@"静音.png");

            label1.Text = "";
            label2.Text = "";
        }

        private void musicPlay_Click(object sender, EventArgs e)
        {
            musicPlayer.Ctlcontrols.play();
        }

        private void musicPause_Click(object sender, EventArgs e)
        {
            musicPlayer.Ctlcontrols.pause();
        }

        private void musicStop_Click(object sender, EventArgs e)
        {
            musicPlayer.Ctlcontrols.stop();
        }

        bool flag = true;
        /// <summary>
        /// 音乐播放/暂停
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void musicPlayOrPause_Click(object sender, EventArgs e)
        {
            if (listBox1.Items.Count == 0) 
            {
                return;
            }
            if (musicPlayOrPause.Text == "播放")
            {
                if (flag) 
                {
                    musicPlayer.URL = musicPath[listBox1.SelectedIndex];
                }
                musicPlayer.Ctlcontrols.play();
                musicPlayOrPause.Text = "暂停";
            }
            else 
            {
                musicPlayer.Ctlcontrols.pause();
                musicPlayOrPause.Text = "播放";
                flag = false;
            }
        }

        private void musicSelect_Click(object sender, EventArgs e)
        {
            openFileDialog1.ShowDialog();
        }

        List<string> musicPath = new List<string>();
        private void openFileDialog1_FileOk(object sender, CancelEventArgs e)
        {
            //musicPath.AddRange(openFileDialog1.FileNames.ToList());
            string[] strTemp = openFileDialog1.FileNames;
            for (int i = 0; i <strTemp.Length; i++)
            {
                musicPath.Add(strTemp[i]);
                listBox1.Items.Add(Path.GetFileNameWithoutExtension(strTemp[i]));    
            }
        }

        /// <summary>
        /// 双击播放音乐
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void listBox1_DoubleClick(object sender, EventArgs e)
        {
            if (listBox1.Items.Count == 0) 
            {
                return;
            }
            musicPlayer.settings.autoStart = true;
            musicPlayer.URL = musicPath[listBox1.SelectedIndex];

            musicType();

            playLrc(musicPath[listBox1.SelectedIndex]);
        }


        /// <summary>
        /// 上一首
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void musicNext_Click(object sender, EventArgs e)
        {
            try
            {
                int i = listBox1.SelectedIndex - 1;
                listBox1.SelectedItems.Clear();
                if (i == -1)
                {
                    i = listBox1.Items.Count - 1;
                }
                musicPlayer.URL = musicPath[i];
                listBox1.SelectedIndex = i;

                musicType();
            }
            catch 
            {
                
            }
        }

        /// <summary>
        /// 下一首
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void musicLast_Click(object sender, EventArgs e)
        {
            try
            {
                int i = listBox1.SelectedIndex + 1;
                listBox1.SelectedItems.Clear();
                if (i > listBox1.Items.Count - 1)
                {
                    i = 0;
                }
                musicPlayer.URL = musicPath[i];
                listBox1.SelectedIndex = i;

                musicType();
            }
            catch
            {
                
            }
        }

        /// <summary>
        /// 音量+
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnMusicUp_Click(object sender, EventArgs e)
        {
            musicPlayer.settings.volume += 3;
        }
        public void musicType() 
        {
            if (musicPlayOrPause.Text == "播放")
            {
                musicPlayOrPause.Text = "暂停";
            }
        }

        private void btnMusicDown_Click(object sender, EventArgs e)
        {
            musicPlayer.settings.volume -= 3;
        }

        /// <summary>
        /// 单机静音/放音按钮
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button1_Click(object sender, EventArgs e)
        {
            if (btnMute.Tag.ToString() == "1")
            {
                btnMute.Image = Image.FromFile(@"放音.png");
                musicPlayer.settings.mute = true;
                btnMute.Tag = "2";
            }
            else 
            {
                btnMute.Image = Image.FromFile(@"静音.png");
                musicPlayer.settings.mute = false;
                btnMute.Tag = "1";
            }
        }

        /// <summary>
        /// 删除所选定的音乐路径
        /// 1. 删除 list musicPath
        /// 2. 删除listbox1.items
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void 删除ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            int count = listBox1.SelectedIndices.Count;
            for (int i = count-1; i >= 0 ; i--)
            {
                //先删集合 再删listbox1
                //因为集合删除的下标根据listbox1来的
                musicPath.RemoveAt(listBox1.SelectedIndices[i]);
                listBox1.Items.RemoveAt(listBox1.SelectedIndices[i]);
            }
        }

        /// <summary>
        /// 当播放器的状态发生改变时发生的事件
        /// 播放器有5种状态
        /// Ready、Playing、Paused、MediaEnded、Stop
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void musicPlayer_PlayStateChange(object sender, AxWMPLib._WMPOCXEvents_PlayStateChangeEvent e)
        {
            //当播放器状态为MediaEnded的时候开始选择下一曲需要播放的曲目
            //并且播放器进入Ready的状态
            if (musicPlayer.playState == WMPLib.WMPPlayState.wmppsMediaEnded) 
            {
                int i = listBox1.SelectedIndex + 1;
                //因为是多选，播放下一曲的时候先清空之前选择的歌曲
                listBox1.SelectedIndices.Clear();
                if (i == listBox1.Items.Count)
                {
                    i = 0;
                }
                musicPlayer.URL = musicPath[i];
                listBox1.SelectedIndex = i;
            }

            //当播放器的状态为Ready的时候 播放下一曲
            if (musicPlayer.playState == WMPLib.WMPPlayState.wmppsReady)
            {
                try
                {
                    musicPlayer.Ctlcontrols.play();
                }
                catch
                {
                }
            }
        }

        /// <summary>
        /// 每100毫秒把输出歌曲的总时间和当前时间
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void timer1_Tick(object sender, EventArgs e)
        {
            if (musicPlayer.playState == WMPLib.WMPPlayState.wmppsPlaying)
            {
                label1.Text = musicPlayer.currentMedia.duration.ToString() + "\r\n" //获取歌曲的总时间，以精确秒数表示
                    + musicPlayer.currentMedia.durationString +"\r\n"//获取歌曲的总时间，精确表示，以 00：00
                    + musicPlayer.Ctlcontrols.currentPosition.ToString() +"\r\n"//获取歌曲已播放的时间，以精确秒数表示
                    + musicPlayer.Ctlcontrols.currentPositionString;//获取歌曲已播放时间，以 00：00 表示
            }
        }


        string[] strLrc;
        string[] strTime;
        /// <summary>
        /// 初始化歌词
        /// </summary>
        /// <param name="musicLrcPath"></param>
        public void playLrc(string musicLrcPath) 
        {
            musicLrcPath += ".lrc";
            if (File.Exists(musicLrcPath))
            {
                label2.Text = "已找到歌词！";
                //[00:20.88]未来没人能够预测  strTemp[0]
                //[00:25.20]被谁喜欢 又喜欢谁呢 strTemp[1]
                string[] strTemp = File.ReadAllLines(musicLrcPath, Encoding.Default);

                //歌词数组
                strLrc = new string[strTemp.Length];
                //歌词对应的时间的数组
                strTime = new string[strTemp.Length];

                for (int i = 0; i < strTemp.Length; i++)
                {
                    string[] strTempNew = strTemp[i].Split(new char[] { '[', ']' }, StringSplitOptions.RemoveEmptyEntries);
                    strTime[i] = strTempNew[0];
                    strLrc[i] = strTempNew[1];
                }
            }
            else {
                label2.Text = "歌词不存在！";
            }
        }


        /// <summary>
        /// 每10毫秒做一次判断,输出歌词
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void timer2_Tick(object sender, EventArgs e)
        {
            try
            {
                //当音乐播放的时候开始判断
                if (musicPlayer.playState == WMPLib.WMPPlayState.wmppsPlaying)
                {
                    if (File.Exists(musicPath[listBox1.SelectedIndex] + ".lrc"))
                    {
                        for (int i = 0; i < strTime.Length; i++)
                        {
                            if (i == strTime.Length - 1)
                            {
                                label2.Text = strLrc[strTime.Length - 1];
                            }
                            else
                            {
                                string[] temp = strTime[i].Split(new char[] { ':' }, StringSplitOptions.RemoveEmptyEntries);
                                string[] temp2 = strTime[i + 1].Split(new char[] { ':' }, StringSplitOptions.RemoveEmptyEntries);
                                double n1 = double.Parse(temp[0]) * 60 + double.Parse(temp[1]);
                                double n2 = double.Parse(temp2[0]) * 60 + double.Parse(temp2[1]);
                                if (musicPlayer.Ctlcontrols.currentPosition >= n1 && musicPlayer.Ctlcontrols.currentPosition <= n2)
                                {
                                    label2.Text = strLrc[i];
                                    break;
                                }
                            }
                        }
                    }
                }
                else
                {

                }
            }
            catch {
            }


        }



    }
}
