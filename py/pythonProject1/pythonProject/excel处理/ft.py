import string

import openpyxl
import jieba
workbook=openpyxl.load_workbook("JayMe.xlsx")
sheet=workbook["jayme"]
cell_description=sheet['D1:D20']
for i in range(0,20):
      for j in cell_description[i]:
            s=j.value
            s=str(s)
            if s.isdigit() :
                  temp=str(i+1)
                  sheet[str('D'+temp)]=' nononon'
      # new_s=jieba.cut(s,cut_all=False)
            # print('/'.join(new_s))

workbook.save("Jaym1e.xlsx")