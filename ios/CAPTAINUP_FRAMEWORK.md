# CaptainUp iOS Framework

Place the `CaptainUp.xcframework` folder here (download from the CaptainUp SDK distribution):

```
ios/
  CaptainUp.xcframework/   ← drop it here
  Captainup.swift
  Captainup.mm
  Captainup-Bridging-Header.h
```

The podspec references it via:
```ruby
s.vendored_frameworks = 'ios/CaptainUp.xcframework'
```

## After adding the framework

Run `pod install` in the example app:
```sh
cd example/ios && pod install
```

## Verifying headers

Inspect the public API to confirm class/method names match what's in `Captainup.swift`:
```sh
ls ios/CaptainUp.xcframework/ios-arm64/CaptainUp.framework/Headers/
```
