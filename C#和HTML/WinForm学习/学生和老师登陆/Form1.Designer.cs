namespace 学生和老师登陆
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
            this.lblUserName = new System.Windows.Forms.Label();
            this.lblPassWord = new System.Windows.Forms.Label();
            this.txtUserName = new System.Windows.Forms.TextBox();
            this.txtPassWord = new System.Windows.Forms.TextBox();
            this.btnEnter = new System.Windows.Forms.Button();
            this.rbStudent = new System.Windows.Forms.RadioButton();
            this.rbTeacher = new System.Windows.Forms.RadioButton();
            this.SuspendLayout();
            // 
            // lblUserName
            // 
            this.lblUserName.AutoSize = true;
            this.lblUserName.Location = new System.Drawing.Point(59, 89);
            this.lblUserName.Name = "lblUserName";
            this.lblUserName.Size = new System.Drawing.Size(41, 12);
            this.lblUserName.TabIndex = 0;
            this.lblUserName.Text = "用户名";
            // 
            // lblPassWord
            // 
            this.lblPassWord.AutoSize = true;
            this.lblPassWord.Location = new System.Drawing.Point(71, 132);
            this.lblPassWord.Name = "lblPassWord";
            this.lblPassWord.Size = new System.Drawing.Size(29, 12);
            this.lblPassWord.TabIndex = 1;
            this.lblPassWord.Text = "密码";
            // 
            // txtUserName
            // 
            this.txtUserName.Location = new System.Drawing.Point(106, 86);
            this.txtUserName.Name = "txtUserName";
            this.txtUserName.Size = new System.Drawing.Size(192, 21);
            this.txtUserName.TabIndex = 2;
            // 
            // txtPassWord
            // 
            this.txtPassWord.Location = new System.Drawing.Point(106, 129);
            this.txtPassWord.Name = "txtPassWord";
            this.txtPassWord.PasswordChar = '*';
            this.txtPassWord.Size = new System.Drawing.Size(192, 21);
            this.txtPassWord.TabIndex = 3;
            // 
            // btnEnter
            // 
            this.btnEnter.Location = new System.Drawing.Point(242, 212);
            this.btnEnter.Name = "btnEnter";
            this.btnEnter.Size = new System.Drawing.Size(56, 33);
            this.btnEnter.TabIndex = 4;
            this.btnEnter.Text = "登陆";
            this.btnEnter.UseVisualStyleBackColor = true;
            this.btnEnter.Click += new System.EventHandler(this.btnEnter_Click);
            // 
            // rbStudent
            // 
            this.rbStudent.AutoSize = true;
            this.rbStudent.Location = new System.Drawing.Point(106, 170);
            this.rbStudent.Name = "rbStudent";
            this.rbStudent.Size = new System.Drawing.Size(47, 16);
            this.rbStudent.TabIndex = 5;
            this.rbStudent.TabStop = true;
            this.rbStudent.Text = "学生";
            this.rbStudent.UseVisualStyleBackColor = true;
            // 
            // rbTeacher
            // 
            this.rbTeacher.AutoSize = true;
            this.rbTeacher.Location = new System.Drawing.Point(251, 170);
            this.rbTeacher.Name = "rbTeacher";
            this.rbTeacher.Size = new System.Drawing.Size(47, 16);
            this.rbTeacher.TabIndex = 6;
            this.rbTeacher.TabStop = true;
            this.rbTeacher.Text = "教师";
            this.rbTeacher.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(552, 469);
            this.Controls.Add(this.rbTeacher);
            this.Controls.Add(this.rbStudent);
            this.Controls.Add(this.btnEnter);
            this.Controls.Add(this.txtPassWord);
            this.Controls.Add(this.txtUserName);
            this.Controls.Add(this.lblPassWord);
            this.Controls.Add(this.lblUserName);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblUserName;
        private System.Windows.Forms.Label lblPassWord;
        private System.Windows.Forms.TextBox txtUserName;
        private System.Windows.Forms.TextBox txtPassWord;
        private System.Windows.Forms.Button btnEnter;
        private System.Windows.Forms.RadioButton rbStudent;
        private System.Windows.Forms.RadioButton rbTeacher;
    }
}

