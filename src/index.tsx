import {
  NativeModules,
  NativeEventEmitter,
  Platform,
  type EmitterSubscription,
} from 'react-native';

const LINKING_ERROR =
  `The package 'react-native-captainup' doesn't seem to be linked. Make sure: \n\n` +
  Platform.select({ ios: "- You have run 'pod install'\n", default: '' }) +
  '- You rebuilt the app after installing the package\n' +
  '- You are not using Expo Go\n';

const CaptainupNative = NativeModules.Captainup
  ? NativeModules.Captainup
  : new Proxy(
      {},
      {
        get() {
          throw new Error(LINKING_ERROR);
        },
      }
    );

const eventEmitter = new NativeEventEmitter(CaptainupNative);

// ---------- Types ----------

export interface Badge {
  id: string;
  name: string;
  description: string;
}

export interface Level {
  number: number;
  name: string;
}

// ---------- Core API ----------

/**
 * Configure the CaptainUp SDK with your API key and mobile token.
 * Must be called before authenticate(). Safe to call multiple times (idempotent).
 */
export function initialize(apiKey: string, mobileToken: string): Promise<void> {
  return CaptainupNative.initialize(apiKey, mobileToken);
}

/**
 * Authenticate a user with the CaptainUp platform.
 * Resolves when the SDK confirms authentication.
 * Rejects if initialize() was not called first or if authentication fails.
 */
export function authenticate(userId: string, userName: string): Promise<void> {
  return CaptainupNative.authenticate(userId, userName);
}

/**
 * Send a named action for the currently authenticated user.
 * Rejects if no user is authenticated.
 */
export function sendAction(actionName: string): Promise<void> {
  return CaptainupNative.sendAction(actionName);
}

// ---------- Event subscriptions ----------

/**
 * Subscribe to badge achievement events.
 * Call .remove() on the returned subscription to unsubscribe.
 */
export function onBadgesAchieved(
  callback: (badges: Badge[]) => void
): EmitterSubscription {
  return eventEmitter.addListener('onBadgesAchieved', callback);
}

/**
 * Subscribe to level update events.
 * Call .remove() on the returned subscription to unsubscribe.
 */
export function onLevelUpdate(
  callback: (levels: Level[]) => void
): EmitterSubscription {
  return eventEmitter.addListener('onLevelUpdate', callback);
}
