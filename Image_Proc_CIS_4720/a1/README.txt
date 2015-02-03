Horia “Ryder” Stancescu
hstances 	-0721385

All the python code is launched from Analyze.py

All images in Noise folder will get a filter applied and the corresponding image gets placed in improved_images, therefore do not relocate nor delete any of the folders.

To apply Filters toggle applyFilter on line 69 to True before running

To apply calc SSIM toggle calculateSSIM on line 70 to True before running

To apply calc NAI toggle calculateNAI on line 71 to True before running

Example of how log files were created:
(once the wanted task is set to True, and the unwanted set to false)

Command Line:
python Analyze.py > LogFileName.txt
