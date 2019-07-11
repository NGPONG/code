using Microsoft.International.Converters.PinYinConverter;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WP.Demo.Common
{
    public static class ChineseCharConvertHelper
    {
        /// <summary>
        ///  获取文本的首字母
        /// </summary>
        /// <param name="str"></param>
        /// <returns></returns>
        public static string GetTextInital(string strConvert) 
        {
            string strResult = string.Empty;

            for (int i = 0; i < strConvert.Length; i++)
            {
                ChineseChar cc = new ChineseChar(strConvert[i]);
                // 通过Pinyins属性，获取构造函数接收到的char类型中文字符的拼音，返回的集合包含该中文字符的多种拼音的不同发音
                ReadOnlyCollection<string> roc = cc.Pinyins;
                strResult += roc[0][0];
            }

            return strResult;
        }
    }
}
