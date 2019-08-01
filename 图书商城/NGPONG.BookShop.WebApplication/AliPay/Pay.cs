using NGPONG.BookShop.Common.Unitis;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Web;

namespace BookShop.Web.AliPay
{
    public class Pay
    {
        public Pay(string subject, string body, string out_trade_no, decimal total_fee)
        {
            this.partner = ConfigurationManager.AppSettings["partner"];
            this.return_url = ConfigurationManager.AppSettings["return_url"];
            this.seller_email = ConfigurationManager.AppSettings["seller_email"];
            this.key = ConfigurationManager.AppSettings["key"];
            this.payGateUrl = ConfigurationManager.AppSettings["payGateUrl"];
            this.subject = subject;
            this.body = body;
            this.out_trade_no = out_trade_no;
            this.total_fee = total_fee;
            this.sign = WebCommon.GetMd5String(total_fee + partner + out_trade_no + subject + key).ToLower();
        }
        public string GoPay()
        {
            return string.Format("{0}?partner={1}&return_url={2}&subject={3}&body={4}&out_trade_no={5}&total_fee={6}&seller_email={7}&sign={8}", payGateUrl, partner, return_url, subject, body, out_trade_no, total_fee, seller_email, sign);
        }

        #region Member
        private string partner;
        public string Partner
        {
            get { return partner; }
            set { partner = value; }
        }
        private string return_url;
        public string Return_url
        {
            get { return return_url; }
            set { return_url = value; }
        }
        private string subject;
        public string Subject
        {
            get { return subject; }
            set { subject = value; }
        }
        private string body;
        public string Body
        {
            get { return body; }
            set { body = value; }
        }
        private string out_trade_no;
        public string Out_trade_no
        {
            get { return out_trade_no; }
            set { out_trade_no = value; }
        }
        private decimal total_fee;
        public decimal Total_fee
        {
            get { return total_fee; }
            set { total_fee = value; }
        }
        private string seller_email;
        public string Seller_email
        {
            get { return seller_email; }
            set { seller_email = value; }
        }
        private string sign;
        public string Sign
        {
            get { return sign; }
            set { sign = value; }
        }

        private string key;//密钥    --1
        public string Key
        {
            get { return key; }
            set { key = value; }
        }

        private string payGateUrl;//支付地址 1
        public string PayGateUrl
        {
            get { return payGateUrl; }
            set { payGateUrl = value; }
        }

        #endregion
    }
}