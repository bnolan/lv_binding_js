import { Button, Line, Render, Text, View } from "lvgljs-ui";
import React, { useEffect, useState } from "react";

const URL = "https://mastodon.social/api/v1/timelines/public";

const dark = "#303030";
const light = "#f3f3f3";

function App() {
  const [data, setData] = useState([]);

  useEffect(() => {
    fetch(URL)
      .then((response) => response.json())
      .then((data) =>
        setData(data.map((post) => post.content.replace(/<[^>]*>?/gm, ""))),
      )
      .catch((error) => console.error("Error:", error));
  }, []);

  return (
    <View
      style={{
        width: 320,
        height: 240,
        "background-color": light,
        display: "flex",
        "flex-direction": "column",
      }}
    >
      <Text style={{ "font-size": 24, "text-color": dark }}>
        {data.length} posts
      </Text>
      {data.map((post) => (
        <>
          <Text style={{ "text-color": dark }}>{post.slice(0, 32)}...</Text>
          <Line
            style={{ "line-color": dark }}
            points={[
              [0, 0],
              [320, 0],
            ]}
          />
        </>
      ))}
    </View>
  );
}

Render.render(<App />);
