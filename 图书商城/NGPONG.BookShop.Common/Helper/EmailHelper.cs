using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Mail;
using System.Text;
using System.Threading.Tasks;

namespace NGPONG.BookShop.Common.Helper
{
    public static class EmailHelper
    {
        /// <summary>
        /// 发送邮件
        /// </summary>
        /// <param name="receiveUserEmail"></param>
        /// <param name="sendContent"></param>
        /// <param name="sendSubject"></param>
        /// <param name="isBodyHtml"></param>
        public static void SendEmail(string receiveUserEmail, string sendContent, string sendSubject, bool isBodyHtml = true)
        {
            MailMessage mail = new MailMessage();
            // 设置邮件寄件人和收件人
            mail.From = new MailAddress("pengpeng1997428@163.com", "NGPONG");
            mail.To.Add(receiveUserEmail);
            // 设置邮件标题
            mail.SubjectEncoding = Encoding.UTF8;
            mail.Subject = sendSubject;
            // 设置邮件主体信息
            mail.BodyEncoding = Encoding.UTF8;  
            mail.IsBodyHtml = isBodyHtml;
            mail.Body = sendContent;
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
            smtpService.Timeout = 10000;

            smtpService.Send(mail);
        }
    }
}
