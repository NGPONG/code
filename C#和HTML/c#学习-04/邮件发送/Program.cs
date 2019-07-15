using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Mail;
using System.Text;
using System.Threading.Tasks;

namespace 邮件发送
{
    class Program
    {
        static void Main(string[] args)
        {
            FirstWay();
            Console.WriteLine("发送成功!");
            Console.ReadKey(true);
        }

        public static void FirstWay()
        {
            MailMessage mail = new MailMessage();
            // 设置邮件寄件人和收件人
            mail.From = new MailAddress("pengpeng1997428@163.com", "NGPONG");
            mail.To.Add("1917648573@qq.com");
            // 设置邮件标题
            mail.SubjectEncoding = Encoding.UTF8;
            mail.Subject = "Test mail";
            // 设置邮件主体信息
            mail.BodyEncoding = Encoding.UTF8;
            mail.IsBodyHtml = false;
            mail.Body = "测试邮件!by_ngpong";
            // 设置邮件发送优先级
            mail.Priority = MailPriority.High;

            SmtpClient smtpService = new SmtpClient();
            smtpService.Host = "smtp.163.com";
            smtpService.Port = 25;
            // 设置登录信息
            smtpService.UseDefaultCredentials = false;
            smtpService.Credentials = new NetworkCredential("pengpeng1997428@163.com", "pengqi1997428");
            // 指定发送方式
            smtpService.DeliveryMethod = SmtpDeliveryMethod.Network;
            // 启用SSL加密连接
            smtpService.EnableSsl = true;
            // 超时时间
            // smtpService.Timeout = 10000;
            smtpService.Send(mail);
        }

        [Obsolete]
        public static void SecondWay()
        {
            System.Web.Mail.MailMessage mail = new System.Web.Mail.MailMessage();

            mail.To = "1917648573@qq.com";
            mail.From = "pengpeng1997428@gmail.com";
            mail.Subject = "这是主题";
            mail.BodyFormat = System.Web.Mail.MailFormat.Html;
            mail.Body = "这是内容";

            mail.Fields.Add("http://schemas.microsoft.com/cdo/configuration/smtpauthenticate", "1"); //身份验证
            mail.Fields.Add("http://schemas.microsoft.com/cdo/configuration/sendusername", mail.From); //邮箱登录账号，这里跟前面的发送账号一样就行
            mail.Fields.Add("http://schemas.microsoft.com/cdo/configuration/sendpassword", "pengqi1997.0428"); //这个密码要注意：如果是一般账号，要用授权码；企业账号用登录密码
            mail.Fields.Add("http://schemas.microsoft.com/cdo/configuration/smtpserverport", 465);//端口
            mail.Fields.Add("http://schemas.microsoft.com/cdo/configuration/smtpusessl", "true");//SSL加密
            System.Web.Mail.SmtpMail.SmtpServer = "smtp.gmail.com";    //企业账号用smtp.exmail.qq.com
            System.Web.Mail.SmtpMail.Send(mail);
        }
    }
}
