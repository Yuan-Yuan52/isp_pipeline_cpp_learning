# ISP Pipeline C++

學習目標：用 C++ 實作完整的 ISP (Image Signal Processing) Pipeline
求職目標：ISP 演算法工程師 / AOI 影像工程師

## 環境
- Windows 11
- GCC 16.1.0 (MinGW-W64)
- CMake 4.3.3
- OpenCV 4.10.0
- LibRaw 0.22.1

## 學習進度

### Week 1 ✅ C++ 專案開發基礎
- [x] Day 1: 環境建立、Git 設定
- [x] Day 2: CMake 多檔案專案、Image class
- [x] Day 3: 指標與記憶體管理
- [x] Day 4: OOP、繼承、virtual、多型
- [x] Day 5: Debugger、fill/crop 整合練習

### Week 2 ✅ OpenCV 入門
- [x] Day 1: OpenCV 安裝、第一個程式
- [x] Day 2: 色彩空間轉換、像素操作
- [x] Day 3: 濾波、Histogram 等化
- [x] Day 4: Canny 邊緣偵測、重寫 MATLAB 作業
- [x] Day 5: Bilateral Filter、整合練習

### Week 3 🔄 OpenCV 進階 + RAW 格式
- [x] Day 1: 形態學運算
- [x] Day 2: LibRaw 安裝、讀取 RAW 資訊
- [x] Day 3: Bayer 資料視覺化
- [x] Day 4: ISP Pipeline 架構設計
- [ ] Day 5: Black Level Correction

### Week 4 ⏳ ISP Pipeline 前半
- [ ] Black Level Correction 完整實作
- [ ] White Balance
- [ ] Demosaicing

### Week 5 ⏳ ISP Pipeline 後半
- [ ] Noise Reduction
- [ ] Tone Mapping
- [ ] Sharpening
- [ ] 完整 Pipeline 串接

### Week 6 ⏳ 效能優化
- [ ] Benchmark 量測
- [ ] OpenMP 多執行緒
- [ ] 記憶體優化

### Week 7 ⏳ Portfolio 整理
- [ ] GitHub README 完善
- [ ] Before/After 效果圖
- [ ] 面試準備

## 專案結構
isp-pipeline-cpp/
├── CMakeLists.txt
├── main.cpp
├── include/
│   ├── image.h
│   ├── raw_image.h
│   ├── isp_pipeline.h
│   └── modules/
└── src/
    ├── image.cpp
    ├── raw_image.cpp
    ├── isp_pipeline.cpp
    └── modules/

進階ISP

邊緣響應法 (Edge Response Method, SFR/MTF)
斜邊演算法 (Slanted-Edge MTF)
鄰近像素比較法 (Neighbor Pixel Comparison)
全域/區域均勻度分析 (Mura & Flat-field Detection)
相機輻射損失補償 (Inverse Sparse Grid)
統計門檻法 (Statistical Threshold)
One-Class SVM
隔離森林 (Isolation Forest / Robust Random Cut Forest)
嗎?