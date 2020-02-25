# Invoice-Divider 2.0.5
This version improved import and export of data. (sub-2)

### New Feature:
1. This version allows user to import data from .xls and .xlsx files with a specific format, which is:
> * Column titles are in the first row with the order of "发票", "项目", "单价", "数量", "总价".
> * All the other rows are formed with values in the order same as the above.
> * Following is the example:
>> ![Sample Import](https://github.com/JiahaoZhu11/Invoice-Divider/blob/2.0.5/Invoice%20Divider/import%20test.png)
2. This version allows user to export data to .txt files with a specific format, which is:
> * Column titles are in the first row with the order of "发票", "项目", "单价", "数量", "总价".
> * The rest rows are the same as in the resulting list.
>> ![Sample Export](https://github.com/JiahaoZhu11/Invoice-Divider/blob/2.0.5/Invoice%20Divider/export%20test.png)
3. Users can decide whether or not to open the folder after saving the file.

### Special Notes:
The function to read and write .xls and xlsx files are based on LibXL.
