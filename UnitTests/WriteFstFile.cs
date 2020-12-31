using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Fst.Test
{
    [TestClass]
    public class WriteFstFile
    {
        [TestMethod]
        public void WriteFile()
        {
            FstCompressor compressor = new(CompressionAlgorithm.LZ4, 1);
            int nrOfRows = 20000;
            FstTable fstTable = new();

            // Add integer column
            //IntVectorAdapter intVec(nrOfRows, FstColumnAttribute::INT_32_BASE, 0);
            //IntSeq(intVec.Data(), nrOfRows, 0);
            //std::string annotation("annotation");
            //fstTable.SetIntegerColumn(&intVec, 0, annotation);
            fstTable.Columns.Add(new FstColumn()
            {
                Name = "Integer",
                Rows = nrOfRows,
                Type = FstColumnType.Int32
            });

            // Add string column
            //StringColumn strColumn{ };
            //strColumn.AllocateVec(nrOfRows);
            //strColumn.SetEncoding(StringEncoding::LATIN1);
            //shared_ptr<StringVector> strColVec = strColumn.StrVector();
            //std::vector < std::string> *strVec = strColVec->StrVec();

            //(*strVec)[0] = "hoi";
            //(*strVec)[1] = "bla";

            //fstTable.SetStringColumn(static_cast<IStringColumn*>(&strColumn), 1);

            // Set column names
            //vector < std::string> colnames = { "Integer", "Character" };
            //StringArray colNames(colnames);
            //fstTable.SetColumnNames(colNames);

            //ReadWriteTester::WriteReadSingleColumns(fstTable, filePath, 0);

            //ReadWriteTester::WriteReadSingleColumns(fstTable, filePath, 30);

            //ReadWriteTester::WriteReadSingleColumns(fstTable, filePath, 70);
        }
    }
}
