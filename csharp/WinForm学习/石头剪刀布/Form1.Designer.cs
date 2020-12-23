namespace 石头剪刀布
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.lblPlayer = new System.Windows.Forms.Label();
            this.lblComputer = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.lblReferee = new System.Windows.Forms.Label();
            this.btnStone = new System.Windows.Forms.Button();
            this.btnScissors = new System.Windows.Forms.Button();
            this.btnCloth = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.lblWinPlayer = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.lblWinComputer = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(44, 41);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(53, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "玩家出：";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(379, 41);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(53, 12);
            this.label2.TabIndex = 1;
            this.label2.Text = "电脑出：";
            // 
            // lblPlayer
            // 
            this.lblPlayer.AutoSize = true;
            this.lblPlayer.Location = new System.Drawing.Point(91, 41);
            this.lblPlayer.Name = "lblPlayer";
            this.lblPlayer.Size = new System.Drawing.Size(41, 12);
            this.lblPlayer.TabIndex = 2;
            this.lblPlayer.Text = "lable3";
            // 
            // lblComputer
            // 
            this.lblComputer.AutoSize = true;
            this.lblComputer.Location = new System.Drawing.Point(426, 41);
            this.lblComputer.Name = "lblComputer";
            this.lblComputer.Size = new System.Drawing.Size(41, 12);
            this.lblComputer.TabIndex = 3;
            this.lblComputer.Text = "label4";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(199, 189);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(41, 12);
            this.label5.TabIndex = 4;
            this.label5.Text = "裁判：";
            // 
            // lblReferee
            // 
            this.lblReferee.AutoSize = true;
            this.lblReferee.Location = new System.Drawing.Point(246, 189);
            this.lblReferee.Name = "lblReferee";
            this.lblReferee.Size = new System.Drawing.Size(41, 12);
            this.lblReferee.TabIndex = 5;
            this.lblReferee.Text = "label6";
            // 
            // btnStone
            // 
            this.btnStone.Location = new System.Drawing.Point(46, 386);
            this.btnStone.Name = "btnStone";
            this.btnStone.Size = new System.Drawing.Size(75, 23);
            this.btnStone.TabIndex = 6;
            this.btnStone.Text = "石头";
            this.btnStone.UseVisualStyleBackColor = true;
            this.btnStone.Click += new System.EventHandler(this.btnStone_Click);
            // 
            // btnScissors
            // 
            this.btnScissors.Location = new System.Drawing.Point(212, 386);
            this.btnScissors.Name = "btnScissors";
            this.btnScissors.Size = new System.Drawing.Size(75, 23);
            this.btnScissors.TabIndex = 7;
            this.btnScissors.Text = "剪刀";
            this.btnScissors.UseVisualStyleBackColor = true;
            this.btnScissors.Click += new System.EventHandler(this.btnScissors_Click);
            // 
            // btnCloth
            // 
            this.btnCloth.Location = new System.Drawing.Point(392, 385);
            this.btnCloth.Name = "btnCloth";
            this.btnCloth.Size = new System.Drawing.Size(75, 23);
            this.btnCloth.TabIndex = 8;
            this.btnCloth.Text = "布";
            this.btnCloth.UseVisualStyleBackColor = true;
            this.btnCloth.Click += new System.EventHandler(this.btnCloth_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(46, 57);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(29, 12);
            this.label3.TabIndex = 9;
            this.label3.Text = "胜场";
            // 
            // lblWinPlayer
            // 
            this.lblWinPlayer.AutoSize = true;
            this.lblWinPlayer.Location = new System.Drawing.Point(91, 57);
            this.lblWinPlayer.Name = "lblWinPlayer";
            this.lblWinPlayer.Size = new System.Drawing.Size(11, 12);
            this.lblWinPlayer.TabIndex = 10;
            this.lblWinPlayer.Text = "0";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(379, 57);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(29, 12);
            this.label6.TabIndex = 11;
            this.label6.Text = "胜场";
            // 
            // lblWinComputer
            // 
            this.lblWinComputer.AutoSize = true;
            this.lblWinComputer.Location = new System.Drawing.Point(426, 57);
            this.lblWinComputer.Name = "lblWinComputer";
            this.lblWinComputer.Size = new System.Drawing.Size(11, 12);
            this.lblWinComputer.TabIndex = 12;
            this.lblWinComputer.Text = "0";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(494, 453);
            this.Controls.Add(this.lblWinComputer);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.lblWinPlayer);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.btnCloth);
            this.Controls.Add(this.btnScissors);
            this.Controls.Add(this.btnStone);
            this.Controls.Add(this.lblReferee);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.lblComputer);
            this.Controls.Add(this.lblPlayer);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label lblPlayer;
        private System.Windows.Forms.Label lblComputer;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label lblReferee;
        private System.Windows.Forms.Button btnStone;
        private System.Windows.Forms.Button btnScissors;
        private System.Windows.Forms.Button btnCloth;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label lblWinPlayer;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label lblWinComputer;
    }
}

