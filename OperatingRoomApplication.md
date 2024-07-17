# Capstone Project: Remote Monitoring of Anesthesia Equipment

## Abstract:
Our project developed a mobile application to improve real-time monitoring and communication in operating rooms (ORs). Built using React Native, the app integrates patient data with notifications and a centralized display of relevant patient information, enhancing efficiency and safety in surgical environments. Key stakeholders from the UW School of Medicine were involved throughout the development process, ensuring the app met their needs. An app demo received positive feedback, with 80% of polled physicians finding it useful and easy to adopt.

## Problem Statement:
Current OR communication methods are inefficient and can hinder patient safety and clinical outcomes. This project addresses the need for a system that allows real-time monitoring and communication, improving surgical outcomes and operational efficiency.

## Technology Stack:

Framework: React Native, Expo

Languages: JavaScript, HTML, CSS

Platforms: iOS, Android

## Design Description:
The mobile application displays real-time patient information and allows clinicians to communicate seamlessly. It integrates patient data with notifications and a centralized display of relevant information, improving upon existing solutions like the OR board, Microsoft Teams, and Epic.

## Features:

### OR Board:

• Displays at-a-glance information about each OR, including the surgeon, anesthesiologist, and surgery progression.

• Helps PACU nurses prepare for patient arrivals by showing which surgeries are nearing completion.

<img src="/images/HomeInterface.jpg" alt="Home Interface" style="width: 30%;">

### Detailed OR View:

• Provides granular information for each surgery.

• Uses a JavaScript function to query data from the VitalDB API, simulating real-time updates of patient vitals with a time-elapsed mechanism.

<img src="/images/DetailedOR.jpg" alt="Detailed OR View" style="width: 30%;">

### Messaging:

• Allows anesthesiologists or scrub nurses to update surgery status.

• Displays expected stages for each surgery, enabling users to check off completed steps and send notifications to other app users.

• Includes an Emergency button for notifying clinicians with a buzzing alarm.

<img src="/images/Messaging.jpg" alt="Messaging" style="width: 30%;">

### Profile:

• Shows the current user’s profile, including their picture and email address.

• Tailors the experience to each user, ensuring they receive relevant notifications based on their team.

## Results:

• App Demo: Presented to UW Physicians and at the UW Bioengineering Research Symposium

• Feedback: 80% of polled physicians found the app useful and easy to adopt.

<img src="/images/RemoteAnesthesiaMonitoringPoster.png" alt="PresentationPoster" style="width: 60%;">

GitHub Repository: Capstone Project Repository
