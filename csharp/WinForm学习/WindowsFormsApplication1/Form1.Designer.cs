namespace WindowsFormsApplication1
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
            this.btnNewLine = new System.Windows.Forms.Button();
            this.btnSave = new System.Windows.Forms.Button();
            this.btnAbout = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.textUserName = new System.Windows.Forms.TextBox();
            this.textPassWord = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.textCaptcha = new System.Windows.Forms.TextBox();
            this.btnCaptcha = new System.Windows.Forms.Button();
            this.btnEnter = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnNewLine
            // 
            this.btnNewLine.Location = new System.Drawing.Point(12, 12);
            this.btnNewLine.Name = "btnNewLine";
            this.btnNewLine.Size = new System.Drawing.Size(140, 40);
            this.btnNewLine.TabIndex = 0;
            this.btnNewLine.Text = "自动换行";
            this.btnNewLine.UseVisualStyleBackColor = true;
            this.btnNewLine.Click += new System.EventHandler(this.btnNewLine_Click);
            // 
            // btnSave
            // 
            this.btnSave.Location = new System.Drawing.Point(404, 12);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(140, 39);
            this.btnSave.TabIndex = 1;
            this.btnSave.Text = "保存";
            this.btnSave.UseVisualStyleBackColor = true;
            this.btnSave.Click += new System.EventHandler(this.btnSave_Click);
            // 
            // btnAbout
            // 
            this.btnAbout.Location = new System.Drawing.Point(858, 12);
            this.btnAbout.Name = "btnAbout";
            this.btnAbout.Size = new System.Drawing.Size(140, 40);
            this.btnAbout.TabIndex = 2;
            this.btnAbout.Text = "关于";
            this.btnAbout.UseVisualStyleBackColor = true;
            this.btnAbout.Click += new System.EventHandler(this.btnAbout_Click);
            // 
            // textBox1
            // 
            this.textBox1.Font = new System.Drawing.Font("宋体", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.textBox1.Location = new System.Drawing.Point(12, 58);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.textBox1.Size = new System.Drawing.Size(986, 583);
            this.textBox1.TabIndex = 3;
            this.textBox1.WordWrap = false;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(409, 183);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(41, 12);
            this.label1.TabIndex = 4;
            this.label1.Text = "账户：";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(409, 214);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(41, 12);
            this.label2.TabIndex = 5;
            this.label2.Text = "密码：";
            // 
            // textUserName
            // 
            this.textUserName.Location = new System.Drawing.Point(456, 180);
            this.textUserName.Name = "textUserName";
            this.textUserName.Size = new System.Drawing.Size(162, 21);
            this.textUserName.TabIndex = 6;
            // 
            // textPassWord
            // 
            this.textPassWord.Location = new System.Drawing.Point(456, 211);
            this.textPassWord.Name = "textPassWord";
            this.textPassWord.PasswordChar = '*';
            this.textPassWord.Size = new System.Drawing.Size(162, 21);
            this.textPassWord.TabIndex = 7;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(397, 249);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(53, 12);
            this.label3.TabIndex = 8;
            this.label3.Text = "验证码：";
            // 
            // textCaptcha
            // 
            this.textCaptcha.Location = new System.Drawing.Point(456, 246);
            this.textCaptcha.Name = "textCaptcha";
            this.textCaptcha.Size = new System.Drawing.Size(88, 21);
            this.textCaptcha.TabIndex = 9;
            // 
            // btnCaptcha
            // 
            this.btnCaptcha.Location = new System.Drawing.Point(550, 244);
            this.btnCaptcha.Name = "btnCaptcha";
            this.btnCaptcha.Size = new System.Drawing.Size(68, 23);
            this.btnCaptcha.TabIndex = 10;
            this.btnCaptcha.Text = "button4";
            this.btnCaptcha.UseVisualStyleBackColor = true;
            this.btnCaptcha.Click += new System.EventHandler(this.btnCaptcha_Click);
            // 
            // btnEnter
            // 
            this.btnEnter.Location = new System.Drawing.Point(456, 290);
            this.btnEnter.Name = "btnEnter";
            this.btnEnter.Size = new System.Drawing.Size(162, 42);
            this.btnEnter.TabIndex = 11;
            this.btnEnter.Text = "登陆";
            this.btnEnter.UseVisualStyleBackColor = true;
            this.btnEnter.Click += new System.EventHandler(this.btnEnter_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1013, 655);
            this.Controls.Add(this.btnEnter);
            this.Controls.Add(this.btnCaptcha);
            this.Controls.Add(this.textCaptcha);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.textPassWord);
            this.Controls.Add(this.textUserName);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.btnAbout);
            this.Controls.Add(this.btnSave);
            this.Controls.Add(this.btnNewLine);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "Form1";
            this.Text = "吴鹏的小记事本";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnNewLine;
        private System.Windows.Forms.Button btnSave;
        private System.Windows.Forms.Button btnAbout;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textUserName;
        private System.Windows.Forms.TextBox textPassWord;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textCaptcha;
        private System.Windows.Forms.Button btnCaptcha;
        private System.Windows.Forms.Button btnEnter;
    }
}

