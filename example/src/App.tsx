import {
  initialize,
  authenticate,
  sendAction,
  onBadgesAchieved,
  onLevelUpdate,
  type Badge,
  type Level,
} from 'react-native-captainup';
import { Text, Button, ScrollView, StyleSheet } from 'react-native';
import { useState, useEffect } from 'react';

// Replace with your real API key and mobile token from the CaptainUp console.
const API_KEY = 'YOUR-API-KEY';
const MOBILE_TOKEN = 'YOUR-MOBILE-TOKEN';

export default function App() {
  const [status, setStatus] = useState('Not initialized');
  const [badges, setBadges] = useState<Badge[]>([]);
  const [levels, setLevels] = useState<Level[]>([]);

  useEffect(() => {
    const badgeSub = onBadgesAchieved((newBadges) => {
      setBadges((prev) => [...prev, ...newBadges]);
    });
    const levelSub = onLevelUpdate((newLevels) => {
      setLevels((prev) => [...prev, ...newLevels]);
    });

    initialize(API_KEY, MOBILE_TOKEN)
      .then(() => {
        setStatus('Initialized');
        return authenticate('test-user-123', 'Test User');
      })
      .then(() => {
        setStatus('Authenticated');
      })
      .catch((err: Error) => {
        setStatus(`Error: ${err.message}`);
      });

    return () => {
      badgeSub.remove();
      levelSub.remove();
    };
  }, []);

  const handleSendAction = () => {
    sendAction('app_open')
      .then(() => setStatus('Action sent'))
      .catch((err: Error) => setStatus(`Action error: ${err.message}`));
  };

  return (
    <ScrollView contentContainerStyle={styles.container}>
      <Text style={styles.heading}>CaptainUp SDK Demo</Text>
      <Text style={styles.status}>Status: {status}</Text>

      <Button title="Send Action: app_open" onPress={handleSendAction} />

      <Text style={styles.section}>Badges earned ({badges.length})</Text>
      {badges.map((badge, i) => (
        <Text key={i} style={styles.item}>
          {badge.name}: {badge.description}
        </Text>
      ))}

      <Text style={styles.section}>Level updates ({levels.length})</Text>
      {levels.map((level, i) => (
        <Text key={i} style={styles.item}>
          Level {level.number}: {level.name}
        </Text>
      ))}
    </ScrollView>
  );
}

const styles = StyleSheet.create({
  container: {
    flexGrow: 1,
    alignItems: 'center',
    justifyContent: 'center',
    padding: 20,
  },
  heading: { fontSize: 22, fontWeight: 'bold', marginBottom: 12 },
  status: { fontSize: 16, marginBottom: 20, color: '#444' },
  section: { fontSize: 18, fontWeight: '600', marginTop: 20, marginBottom: 8 },
  item: { fontSize: 14, color: '#222' },
});
