using NPOI.HSSF.UserModel;
using System;
using System.Collections.Generic;
using System.Data;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WP.Demo.Common
{
    public static class HSSFNPOI
    {
        /// <summary>
        ///  创建Excel表格
        /// </summary>
        /// <param name="dtResult">数据源</param>
        /// <param name="sheetName">工作表名</param>
        /// <param name="storageLocation">存储位置</param>
        /// <param name="fileName">文件名</param>
        public static void CreateExcel(DataTable dtResult, string sheetName, string storageLocation, string fileName)
        {
            // 创建工作本
            HSSFWorkbook workbook = new HSSFWorkbook();

            // 创建工作表
            HSSFSheet sheet = workbook.CreateSheet(sheetName);

            #region 创建列
            HSSFCellStyle cellstyle_Title = workbook.CreateCellStyle();
            cellstyle_Title.Alignment = 2;
            HSSFFont font_Title = workbook.CreateFont();
            font_Title.FontHeightInPoints = 13;
            font_Title.Boldweight = 100;
            cellstyle_Title.SetFont(font_Title); // 设置字体

            HSSFRow row_Title = sheet.CreateRow(0);
            for (int i = 0; i < dtResult.Columns.Count; i++)
            {
                HSSFCell cell_Title = row_Title.CreateCell(i);
                cell_Title.CellStyle = cellstyle_Title;
                cell_Title.SetCellValue(dtResult.Columns[i].ColumnName);

                // 设置列的宽度
                sheet.SetColumnWidth(i, 5000);
            }
            #endregion

            #region 创建单元格
            for (int i = 0; i < dtResult.Rows.Count; i++)
            {
                HSSFRow row = sheet.CreateRow(i + 1);
                for (int j = 0; j < dtResult.Columns.Count; j++)
                {
                    HSSFCell cell = row.CreateCell(j);
                    cell.SetCellValue(dtResult.Rows[i][j].ToString());
                }
            }
            #endregion

            // 保存
            using (FileStream fsWrite = new FileStream(storageLocation + "\\" + fileName + ".xls", FileMode.Create, FileAccess.ReadWrite))
            {
                workbook.Write(fsWrite);
            }
        }
        /// <summary>
        ///  读取Excel表格
        /// </summary>
        /// <param name="sheetName">工作表名</param>
        /// <param name="fleName">存储位置</param>
        /// <returns></returns>
        public static DataTable GetExcel(string sheetName, string fileName)
        {
            // 创建内存表用于保存
            DataTable memoryTable = new DataTable();

            using (FileStream fsRead = new FileStream(fileName, FileMode.OpenOrCreate, FileAccess.Read))
            {
                // 获取工作本
                HSSFWorkbook workbook = new HSSFWorkbook(fsRead);
                // 获取工作表
                HSSFSheet sheet = workbook.GetSheet(sheetName);

                #region 创建列
                HSSFRow row_cell = sheet.GetRow(0);
                int row_cell_index = 0;
                while (true)
                {
                    HSSFCell cell = row_cell.GetCell(row_cell_index);
                    if (cell == null)
                    {
                        break;
                    }
                    memoryTable.Columns.Add(new DataColumn(cell.StringCellValue));

                    row_cell_index++;
                } 
                #endregion

                #region 创建行
                int row_index = 1;
                int cell_index = 0;
                // 创建每行
                while (true)
                {
                    HSSFRow row = sheet.GetRow(row_index);
                    if (row == null)
                    {
                        break;
                    }
                    DataRow dtRow = memoryTable.NewRow();
                    while (true)
                    {
                        HSSFCell cell = row.GetCell(cell_index);
                        if (cell == null)
                        {
                            cell_index = 0;
                            break;
                        }
                        dtRow[cell_index] = cell.StringCellValue;
                        cell_index++;
                    }
                    memoryTable.Rows.Add(dtRow);
                    row_index++;
                } 
                #endregion

            }

            return memoryTable;
        }
    }
}
