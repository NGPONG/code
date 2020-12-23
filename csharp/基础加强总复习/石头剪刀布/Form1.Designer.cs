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
            this.btnCloth = new System.Windows.Forms.Button();
            this.btnScissors = new System.Windows.Forms.Button();
            this.btnStone = new System.Windows.Forms.Button();
            this.lblReferee = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.lblComputer = new System.Windows.Forms.Label();
            this.lblPlayer = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // btnCloth
            // 
            this.btnCloth.Location = new System.Drawing.Point(377, 398);
            this.btnCloth.Name = "btnCloth";
            this.btnCloth.Size = new System.Drawing.Size(75, 23);
            this.btnCloth.TabIndex = 21;
            this.btnCloth.Text = "布";
            this.btnCloth.UseVisualStyleBackColor = true;
            this.btnCloth.Click += new System.EventHandler(this.btnCloth_Click);
            // 
            // btnScissors
            // 
            this.btnScissors.Location = new System.Drawing.Point(197, 399);
            this.btnScissors.Name = "btnScissors";
            this.btnScissors.Size = new System.Drawing.Size(75, 23);
            this.btnScissors.TabIndex = 20;
            this.btnScissors.Text = "剪刀";
            this.btnScissors.UseVisualStyleBackColor = true;
            this.btnScissors.Click += new System.EventHandler(this.btnScissors_Click);
            // 
            // btnStone
            // 
            this.btnStone.Location = new System.Drawing.Point(31, 399);
            this.btnStone.Name = "btnStone";
            this.btnStone.Size = new System.Drawing.Size(75, 23);
            this.btnStone.TabIndex = 19;
            this.btnStone.Text = "石头";
            this.btnStone.UseVisualStyleBackColor = true;
            this.btnStone.Click += new System.EventHandler(this.btnStone_Click);
            // 
            // lblReferee
            // 
            this.lblReferee.AutoSize = true;
            this.lblReferee.Location = new System.Drawing.Point(231, 160);
            this.lblReferee.Name = "lblReferee";
            this.lblReferee.Size = new System.Drawing.Size(41, 12);
            this.lblReferee.TabIndex = 18;
            this.lblReferee.Text = "label6";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(184, 160);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(41, 12);
            this.label5.TabIndex = 17;
            this.label5.Text = "裁判：";
            // 
            // lblComputer
            // 
            this.lblComputer.AutoSize = true;
            this.lblComputer.Location = new System.Drawing.Point(411, 54);
            this.lblComputer.Name = "lblComputer";
            this.lblComputer.Size = new System.Drawing.Size(41, 12);
            this.lblComputer.TabIndex = 16;
            this.lblComputer.Text = "label4";
            // 
            // lblPlayer
            // 
            this.lblPlayer.AutoSize = true;
            this.lblPlayer.Location = new System.Drawing.Point(76, 54);
            this.lblPlayer.Name = "lblPlayer";
            this.lblPlayer.Size = new System.Drawing.Size(41, 12);
            this.lblPlayer.TabIndex = 15;
            this.lblPlayer.Text = "lable3";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(364, 54);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(53, 12);
            this.label2.TabIndex = 14;
            this.label2.Text = "电脑出：";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(29, 54);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(53, 12);
            this.label1.TabIndex = 13;
            this.label1.Text = "玩家出：";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(492, 493);
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
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnCloth;
        private System.Windows.Forms.Button btnScissors;
        private System.Windows.Forms.Button btnStone;
        private System.Windows.Forms.Label lblReferee;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label lblComputer;
        private System.Windows.Forms.Label lblPlayer;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
    }
}

