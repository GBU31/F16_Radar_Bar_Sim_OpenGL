# Environment Setup
To use this software, you must have Tkinter installed and OpenGL in the root dir.
```git clone https://github.com/glfw/glfw.git ```
``` python3 -m pip install -r requirements.txt ```

# Run
``` python3 main.py```



![FCR+(Fire+Control+Radar)+Display](https://github.com/brookehorizon/f16_radar_bars_sim_opengl/assets/86805843/07f8b4b9-0a62-4395-af6b-ffe121f39e3a)


# 1 Bar
If the radar just moves left to right and back that is
considered 1 bar as it will scan just the single 4.9° slice of airspace. however, the radar can scan a larger area of vertical space if it moves down after a scan.


![Screenshot 2023-06-07 220604](https://github.com/brookehorizon/f16_radar_bars_sim_opengl/assets/86805843/dddaa274-aa4e-435d-bb9f-9cea60e9c690)

# 2 Bar

the radar scans left to right, moves down a few
degrees and scans back right to left. Because the radar antenna is pointing
lower the return scan looks at a different area of space than the first scan.

![Screenshot 2023-06-07 220937](https://github.com/brookehorizon/f16_radar_bars_sim_opengl/assets/86805843/8e1a5be0-daf0-4830-97e5-d0e79880a75f)


# 4 Bar

A 4 bar scan covers the most area but takes the longest to complete. A 1 bar
scan covers the least area but is the fastest; the 2 bar scan falls in between.
You trade off coverage for increased refresh rate of targets.

![Screenshot 2023-06-07 221131](https://github.com/brookehorizon/f16_radar_bars_sim_opengl/assets/86805843/644bf6f4-ed6a-41d1-acf9-dfdeb9f4bcd0)



