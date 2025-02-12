import { Button, Render, Text, View } from "lvgljs-ui";
import React from "react";

function App() {
  return (
    <View style={{ "background-color": "blue" }}>
      <Button style={{ "background-color": "black" }}>
        <Text style={{ "text-color": "white" }}>Hello?!</Text>
      </Button>
    </View>
  );
}

Render.render(<App />);
