using NGPONG.BookShop.DAL;
using NGPONG.BookShop.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Mail;
using System.Text;
using System.Threading.Tasks;

namespace NGPONG.BookShop.BLL
{
    public class UsersService
    {
        public bool CheckUserInfoExists(Users model)
        {
            return UsersDAL.CheckUserInfoExists(model);
        }

        public bool CheckUserInfoLogin(Users model)
        {
            return UsersDAL.CheckUserInfoEmail(model);
        }
        public bool CheckUserInfoEmail(Users model)
        {
            return UsersDAL.CheckUserInfoEmail(model);
        }
        public List<Users> GetUserInfo(Users model)
        {
            return UsersDAL.GetUserInfo(model);
        }

        public int AddkUserInfo(Users model)
        {
            return UsersDAL.AddkUserInfo(model);
        }
        public int ChangekUserPwd(Users model)
        {
            return UsersDAL.ChangekUserPwd(model);
        }
        public static void SendEmail(string receiveUserEmail, string sendContent, string sendSubject, bool isBodyHtml = true)
        {
            SettingService settingService = new SettingService();

            MailMessage mail = new MailMessage();
            // 设置邮件寄件人和收件人
            mail.From = new MailAddress(settingService.GetSettingValue($"setting_{"SysSendEmail"}"), settingService.GetSettingValue($"setting_{"SysSendUserName"}"));
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
            smtpService.Host = settingService.GetSettingValue($"setting_{"SysEmailSmtpService"}");
            smtpService.Port = Convert.ToInt32(settingService.GetSettingValue($"setting_{"SysEmailSmtpPort"}"));
            // 设置登录信息
            smtpService.UseDefaultCredentials = false;
            smtpService.Credentials = new NetworkCredential(settingService.GetSettingValue($"setting_{"SysSendEmail"}"), settingService.GetSettingValue($"setting_{"SysSendUserPwd"}"));
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
