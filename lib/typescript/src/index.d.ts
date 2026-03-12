import { type EmitterSubscription } from 'react-native';
export interface Badge {
    id: string;
    name: string;
    description: string;
}
export interface Level {
    number: number;
    name: string;
}
/**
 * Configure the CaptainUp SDK with your API key and mobile token.
 * Must be called before authenticate(). Safe to call multiple times (idempotent).
 */
export declare function initialize(apiKey: string, mobileToken: string): Promise<void>;
/**
 * Authenticate a user with the CaptainUp platform.
 * Resolves when the SDK confirms authentication.
 * Rejects if initialize() was not called first or if authentication fails.
 */
export declare function authenticate(userId: string, userName: string): Promise<void>;
/**
 * Send a named action for the currently authenticated user.
 * Rejects if no user is authenticated.
 */
export declare function sendAction(actionName: string): Promise<void>;
/**
 * Subscribe to badge achievement events.
 * Call .remove() on the returned subscription to unsubscribe.
 */
export declare function onBadgesAchieved(callback: (badges: Badge[]) => void): EmitterSubscription;
/**
 * Subscribe to level update events.
 * Call .remove() on the returned subscription to unsubscribe.
 */
export declare function onLevelUpdate(callback: (levels: Level[]) => void): EmitterSubscription;
//# sourceMappingURL=index.d.ts.map