# Remote Monitoring of Anesthesia Equipment

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

### Detailed OR View:

• Provides granular information for each surgery.

• Uses a JavaScript function to query data from the VitalDB API, simulating real-time updates of patient vitals with a time-elapsed mechanism.

### Messaging:

• Allows anesthesiologists or scrub nurses to update surgery status.

• Displays expected stages for each surgery, enabling users to check off completed steps and send notifications to other app users.

• Includes an Emergency button for notifying clinicians with a buzzing alarm.

### Profile:

• Shows the current user’s profile, including their picture and email address.

• Tailors the experience to each user, ensuring they receive relevant notifications based on their team.

### Results:

• App Demo: Presented to UW Physicians.

• Feedback: 80% of polled physicians found the app useful and easy to adopt.

GitHub Repository: Capstone Project Repository

## Key Code Highlights:

OR Board Component:
javascript
Copy code
import React from 'react';
import { View, Text } from 'react-native';

const ORBoard = ({ orData }) => {
  return (
    <View>
      {orData.map((or, index) => (
        <View key={index}>
          <Text>{`OR: ${or.room}`}</Text>
          <Text>{`Surgeon: ${or.surgeon}`}</Text>
          <Text>{`Anesthesiologist: ${or.anesthesiologist}`}</Text>
          <Text>{`Progress: ${or.progress}`}</Text>
        </View>
      ))}
    </View>
  );
};

export default ORBoard;
Detailed OR View Component:
javascript
Copy code
import React, { useState, useEffect } from 'react';
import { View, Text } from 'react-native';
import axios from 'axios';

const DetailedORView = ({ orId }) => {
  const [vitals, setVitals] = useState([]);

  useEffect(() => {
    const fetchVitals = async () => {
      const response = await axios.get(`https://vitaldb.example.com/api/vitals/${orId}`);
      setVitals(response.data);
    };
    fetchVitals();
  }, [orId]);

  return (
    <View>
      {vitals.map((vital, index) => (
        <View key={index}>
          <Text>{`Time: ${vital.time}`}</Text>
          <Text>{`Heart Rate: ${vital.heartRate}`}</Text>
          <Text>{`Blood Pressure: ${vital.bloodPressure}`}</Text>
        </View>
      ))}
    </View>
  );
};

export default DetailedORView;
Messaging Component:
javascript
Copy code
import React, { useState } from 'react';
import { View, Text, Button, Alert } from 'react-native';

const Messaging = ({ surgeryStages }) => {
  const [completedStages, setCompletedStages] = useState([]);

  const handleCompleteStage = (stage) => {
    setCompletedStages([...completedStages, stage]);
    Alert.alert('Notification', `${stage} completed`);
  };

  const handleEmergency = () => {
    Alert.alert('Emergency', 'Buzzing alarm for emergency');
  };

  return (
    <View>
      {surgeryStages.map((stage, index) => (
        <View key={index}>
          <Text>{stage}</Text>
          <Button title="Complete" onPress={() => handleCompleteStage(stage)} />
        </View>
      ))}
      <Button title="Emergency" onPress={handleEmergency} />
    </View>
  );
};

export default Messaging;
Visuals and Screenshots
