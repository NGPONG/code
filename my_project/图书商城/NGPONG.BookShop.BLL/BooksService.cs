﻿using BookShop.Model;
using NGPONG.BookShop.DAL;
using NGPONG.BookShop.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NGPONG.BookShop.BLL
{
    public class BooksService
    {
        public List<Book> GetBooksList(int currentPage)
        {
            return new BooksDAL().GetBooksList(currentPage);
        }
        public List<Book> GetBooksList(string bookIds)
        {
            return new BooksDAL().GetBooksList(bookIds);
        }
        public List<Book> GetAllBooksList()
        {
            return new BooksDAL().GetAllBooksList();
        }
    }
}
