## 📹 RaspberryPi-Android-VideoPlayer
A versatile system that bridges a Raspberry Pi and an Android app to enable seamless video capture, playback, and streaming across devices. This project combines mobile app development with embedded systems programming to create a powerful multimedia solution.
 
### 🚀 Project Overview
This system empowers users to capture, stream, and playback video content across multiple sources:
- 🎬 Stream web-hosted videos directly on Android
- 📱 Play locally-stored videos from device storage
- 🎥 Remotely control USB webcam video capture on Raspberry Pi
- 📡 View live video feeds from Raspberry Pi in real-time

### 🗝️ Key Features
1. Android Application
- Intuitive video playback using ExoPlayer for smooth multimedia experience
- Modern Android architecture following best practices
- Network communication via HTTP requests for Pi control
- Multi-source streaming support (web, local, live feeds)
2. Raspberry Pi Integration
- V4L2 API for low-level USB webcam control
- Lightweight HTTP server for remote command handling
- Real-time video processing and streaming capabilities
- FFmpeg integration for video encoding and HLS streaming
3. Network Communication
- HTTP-based control for starting/stopping capture and streams
- Simple request-response pattern for triggering Pi operations
- Cross-platform compatibility enabling Android-to-Pi communication
4. Video Processing Pipeline
- FFmpeg for video encoding and format conversion
- HLS (HTTP Live Streaming) for adaptive live streaming
- Raw frame capture with future conversion to MP4 format

### 📱 Android App Main Features
1. 🏠 Home Page 
- Centralized navigation hub for all functionalities
- Quick access to streaming, capture and plaback features
- Direct links to developer’s LinkedIn and GitHub profiles
2. 🌐 Stream Web-Hosted Videos
- Watch internet-hosted videos directly using ExoPlayer
- Current Implementation: Video URLs are hardcoded in the app and tied to each button
- Future Enhancement: Host a JSON file on GitHub Pages containing video metadata: app fetches and parses the JSON to load videos dynam,mically, enabling easy updates without app modifications
3. 📂 Stream Locally-Stored Videos
- Browse and play video files saved on Android device storage
- Seamless playback with ExoPlayer integration
4. 📡 Stream Live Feed from Raspberry Pi
- Start Stream: Tap to send HTTP request to Pi, triggering FFmpeg-based HLS streaming
- View Stream: ExoPlayer displays real-time video feed from Pi's USB webcam
- Stop Stream: Gracefully terminate the streaming process with a tap
- Known Issue: Startup delay may cause crashes if playback starts too early; future versions will implement auto-play once stream is confirmed active
5. 🎥 Capture video on Raspberry Pi
- Start Capture: Remotely trigger video recording via HTTP request to Pi
- Stop Capture: End recording session and save captured frames
- Storage: Captured video frames are stored on Raspberry Pi
- Current Output: Each frame saved as raw .yuyv file (e.g., frame_0.yuyv, frame_1.yuyv)
- Future Enhancement: Automatic conversion to timestamped .mp4 files using FFmpeg; server returns filename to Android app in HTTP response
6. 📹 Stream captured video from Raspberry Pi (_Coming Soon_)
- Stream video during active capture session (Feature 5)
- Browse and stream previously captured videos stored on Pi

### Demo

| ![Demo 1](./1.gif) | ![Demo 2](./2.gif) | ![Demo 3](./3.gif) |
|:------------------:|:------------------:|:------------------:|

