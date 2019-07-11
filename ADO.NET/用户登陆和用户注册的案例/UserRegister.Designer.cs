namespace 用户登陆和用户注册的案例
{
    partial class UserRegister
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
            this.lbUserNameCheckResult = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.txtAge = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.txtPwdResult = new System.Windows.Forms.TextBox();
            this.txtPwd = new System.Windows.Forms.TextBox();
            this.txtUserName = new System.Windows.Forms.TextBox();
            this.btnRegist = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lbUserNameCheckResult
            // 
            this.lbUserNameCheckResult.AutoSize = true;
            this.lbUserNameCheckResult.ForeColor = System.Drawing.Color.Red;
            this.lbUserNameCheckResult.Location = new System.Drawing.Point(244, 39);
            this.lbUserNameCheckResult.Name = "lbUserNameCheckResult";
            this.lbUserNameCheckResult.Size = new System.Drawing.Size(11, 12);
            this.lbUserNameCheckResult.TabIndex = 13;
            this.lbUserNameCheckResult.Text = "*";
            this.lbUserNameCheckResult.Visible = false;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(46, 79);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(41, 12);
            this.label2.TabIndex = 9;
            this.label2.Text = "密码：";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(46, 177);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(41, 12);
            this.label4.TabIndex = 10;
            this.label4.Text = "年龄：";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(46, 130);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(65, 12);
            this.label3.TabIndex = 11;
            this.label3.Text = "密码再次：";
            // 
            // txtAge
            // 
            this.txtAge.Location = new System.Drawing.Point(137, 174);
            this.txtAge.Name = "txtAge";
            this.txtAge.Size = new System.Drawing.Size(100, 21);
            this.txtAge.TabIndex = 5;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(46, 34);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(53, 12);
            this.label1.TabIndex = 12;
            this.label1.Text = "用户名：";
            // 
            // txtPwdResult
            // 
            this.txtPwdResult.Location = new System.Drawing.Point(137, 127);
            this.txtPwdResult.Name = "txtPwdResult";
            this.txtPwdResult.Size = new System.Drawing.Size(100, 21);
            this.txtPwdResult.TabIndex = 6;
            // 
            // txtPwd
            // 
            this.txtPwd.Location = new System.Drawing.Point(137, 79);
            this.txtPwd.Name = "txtPwd";
            this.txtPwd.Size = new System.Drawing.Size(100, 21);
            this.txtPwd.TabIndex = 7;
            // 
            // txtUserName
            // 
            this.txtUserName.Location = new System.Drawing.Point(137, 31);
            this.txtUserName.Name = "txtUserName";
            this.txtUserName.Size = new System.Drawing.Size(100, 21);
            this.txtUserName.TabIndex = 8;
            // 
            // btnRegist
            // 
            this.btnRegist.Location = new System.Drawing.Point(137, 223);
            this.btnRegist.Name = "btnRegist";
            this.btnRegist.Size = new System.Drawing.Size(100, 23);
            this.btnRegist.TabIndex = 4;
            this.btnRegist.Text = "注册";
            this.btnRegist.UseVisualStyleBackColor = true;
            this.btnRegist.Click += new System.EventHandler(this.btnRegist_Click);
            // 
            // UserRegister
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(308, 282);
            this.Controls.Add(this.lbUserNameCheckResult);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.txtAge);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.txtPwdResult);
            this.Controls.Add(this.txtPwd);
            this.Controls.Add(this.txtUserName);
            this.Controls.Add(this.btnRegist);
            this.Name = "UserRegister";
            this.Text = "UserRegister";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lbUserNameCheckResult;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txtAge;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txtPwdResult;
        private System.Windows.Forms.TextBox txtPwd;
        private System.Windows.Forms.TextBox txtUserName;
        private System.Windows.Forms.Button btnRegist;
    }
}